#include <cstdio>

#include "imgui.h"
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlgpu3.h>

#include "gl3_window.h"

bool Gl3Window::DoCreate(CreateParams params)
{
    SdlWindow::DoCreate(params);
    return true;
}

bool Gl3Window::PostCreate(CreateParams params)
{
    // Setup Platform/Renderer backends
    // ImGui_ImplGlfw_InitForOpenGL(window_, true);
    // ImGui_ImplOpenGL3_Init(glsl_version_);

    // Setup Platform/Renderer backends
    // Create GPU Device
    gpu_device_ = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_METALLIB, true, nullptr);
    if (gpu_device_ == nullptr)
    {
        printf("Error: SDL_CreateGPUDevice(): %s\n", SDL_GetError());
        return 1;
    }

    // Claim window for GPU Device
    if (!SDL_ClaimWindowForGPUDevice(gpu_device_, window_))
    {
        printf("Error: SDL_ClaimWindowForGPUDevice(): %s\n", SDL_GetError());
        return 1;
    }
    SDL_SetGPUSwapchainParameters(gpu_device_, window_, SDL_GPU_SWAPCHAINCOMPOSITION_SDR, SDL_GPU_PRESENTMODE_VSYNC);

    ImGui_ImplSDL3_InitForSDLGPU(window_);
    ImGui_ImplSDLGPU3_InitInfo init_info = {};
    init_info.Device = gpu_device_;
    init_info.ColorTargetFormat = SDL_GetGPUSwapchainTextureFormat(gpu_device_, window_);
    init_info.MSAASamples = SDL_GPU_SAMPLECOUNT_1;                     // Only used in multi-viewports mode.
    init_info.SwapchainComposition = SDL_GPU_SWAPCHAINCOMPOSITION_SDR; // Only used in multi-viewports mode.
    init_info.PresentMode = SDL_GPU_PRESENTMODE_VSYNC;
    ImGui_ImplSDLGPU3_Init(&init_info);

    return X11Window::PostCreate(params);
}

void Gl3Window::Draw()
{
}

void Gl3Window::Render()
{
    // Start the Dear ImGui frame
    // ImGui_ImplOpenGL3_NewFrame();
    // ImGui_ImplGlfw_NewFrame();
    ImGui_ImplSDLGPU3_NewFrame();
    ImGui_ImplSDL3_NewFrame();

    ImGui::NewFrame();
    Draw();
    ImGui::Render();

    /*
    int display_w, display_h;
    glfwGetFramebufferSize(window_, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    */

    ImDrawData *draw_data = ImGui::GetDrawData();
    const bool is_minimized = (draw_data->DisplaySize.x <= 0.0f || draw_data->DisplaySize.y <= 0.0f);

    SDL_GPUCommandBuffer *command_buffer = SDL_AcquireGPUCommandBuffer(gpu_device_); // Acquire a GPU command buffer

    SDL_GPUTexture *swapchain_texture;
    SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, window_, &swapchain_texture, nullptr, nullptr); // Acquire a swapchain texture

    if (swapchain_texture != nullptr && !is_minimized)
    {
        // This is mandatory: call ImGui_ImplSDLGPU3_PrepareDrawData() to upload the vertex/index buffer!
        ImGui_ImplSDLGPU3_PrepareDrawData(draw_data, command_buffer);

        // Setup and start a render pass
        SDL_GPUColorTargetInfo target_info = {};
        target_info.texture = swapchain_texture;
        target_info.clear_color = SDL_FColor{clear_color.x, clear_color.y, clear_color.z, clear_color.w};
        target_info.load_op = SDL_GPU_LOADOP_CLEAR;
        target_info.store_op = SDL_GPU_STOREOP_STORE;
        target_info.mip_level = 0;
        target_info.layer_or_depth_plane = 0;
        target_info.cycle = false;
        SDL_GPURenderPass *render_pass = SDL_BeginGPURenderPass(command_buffer, &target_info, 1, nullptr);

        // Render ImGui
        ImGui_ImplSDLGPU3_RenderDrawData(draw_data, command_buffer, render_pass);

        SDL_EndGPURenderPass(render_pass);
    }

    // Update and Render additional Platform Windows
    // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
    //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        // SDL_Window* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        // glfwMakeContextCurrent(backup_current_context);
        //glfwMakeContextCurrent(window_);
    }

    // glfwSwapBuffers(window_);
    //  Submit the command buffer
    SDL_SubmitGPUCommandBuffer(command_buffer);
}

void Gl3Window::Destroy()
{
    // Cleanup
    //ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDLGPU3_Shutdown();
    //ImGui_ImplGlfw_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    X11Window::Destroy();
}

void Gl3Window::OnMouseButton(int button, int action, int mods)
{
    //Display *dpy = glfwGetX11Display();
    //Window win = glfwGetX11Window(window_);
    /*
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            // Force focus to our child immediately
            //XSetInputFocus(dpy, win, RevertToParent, CurrentTime);

            // Keep motion/release with us while dragging
            XGrabPointer(dpy, win, True,
                ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
                GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
            XFlush(dpy);
        } else if (action == GLFW_RELEASE) {
            XUngrabPointer(dpy, CurrentTime);
            XFlush(dpy);
        }
    }
    */
}