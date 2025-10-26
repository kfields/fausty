#include <SDL3/SDL.h>

#include <backends/imgui_impl_sdl3.h>

#include "sdl_window.h"

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

SdlWindow::SdlWindow()
{
}

SdlWindow::~SdlWindow()
{
    Destroy();
}

// Event routing
/*
void window_refresh_callback(SDL_Window *win)
{
  SdlWindow &window = *((SdlWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowRefresh();
}
void window_size_callback(SDL_Window *win, int width, int height)
{
  SdlWindow &window = *((SdlWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowSize(width, height);
}
void window_pos_callback(SDL_Window *win, int xpos, int ypos)
{
  SdlWindow &window = *((SdlWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowPos(xpos, ypos);
}
void window_cursor_pos_callback(SDL_Window *win, double x, double y)
{
  SdlWindow &window = *((SdlWindow *)glfwGetWindowUserPointer(win));
  window.OnCursorPos(x, y);
}
void window_mouse_button_callback(SDL_Window *win, int button, int action, int mods)
{
  SdlWindow &window = *((SdlWindow *)glfwGetWindowUserPointer(win));
  window.OnMouseButton(button, action, mods);
}
void window_focus_callback(SDL_Window *win, int focused)
{
  SdlWindow &window = *((SdlWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowFocus(focused);
}
*/

bool SdlWindow::DoCreate(CreateParams params)
{
    WindowBase::DoCreate(params);
    // CreateContext();

    // Setup window
    // glfwSetErrorCallback(glfw_error_callback);

    /*
    if (!glfwInit())
      return false;
    */
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return false;
    }
    // Create window with graphics context

    is_embedded_ = (params.nativeParent != nullptr);

    /*
    if (is_embedded_)
    {
      glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    }

    window_ = glfwCreateWindow(1280, 720, "Fausty!", NULL, NULL);
    */
    uint32_t sdl_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
    if (is_embedded_)
    {
        sdl_flags |= SDL_WINDOW_BORDERLESS;
    }
    window_ = SDL_CreateWindow(params.title.c_str(),
                               params.size.width,
                               params.size.height,
                               sdl_flags);

    if (window_ == NULL)
        return false;

    if (params.nativeParent)
    {
        NativeAttachTo(params.nativeParent);
    }
    // glfwSetInputMode(window_, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
    // glfwSetWindowAttrib(window_, GLFW_MOUSE_PASSTHROUGH, GLFW_FALSE);

    /*
    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1); // Enable vsync

    glfwSetWindowUserPointer(window_, this);

    glfwSetWindowRefreshCallback(window_, window_refresh_callback);
    glfwSetWindowSizeCallback(window_, window_size_callback);
    glfwSetWindowPosCallback(window_, window_pos_callback);
    glfwSetCursorPosCallback(window_, window_cursor_pos_callback);
    glfwSetMouseButtonCallback(window_, window_mouse_button_callback);
    glfwSetWindowFocusCallback(window_, window_focus_callback);
    */

    /*    
    // Create GPU Device
    SDL_GPUDevice *gpu_device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_METALLIB, true, nullptr);
    if (gpu_device == nullptr)
    {
        printf("Error: SDL_CreateGPUDevice(): %s\n", SDL_GetError());
        return 1;
    }

    // Claim window for GPU Device
    if (!SDL_ClaimWindowForGPUDevice(gpu_device, window_))
    {
        printf("Error: SDL_ClaimWindowForGPUDevice(): %s\n", SDL_GetError());
        return 1;
    }
    SDL_SetGPUSwapchainParameters(gpu_device, window_, SDL_GPU_SWAPCHAINCOMPOSITION_SDR, SDL_GPU_PRESENTMODE_VSYNC);
    */

    return true;
}

bool SdlWindow::PostCreate(CreateParams params)
{
    /*
    glfwSetWindowUserPointer(window_, this);
    glfwSetWindowRefreshCallback(window_, window_refresh_callback);
    glfwSetWindowSizeCallback(window_, window_size_callback);
    glfwSetWindowPosCallback(window_, window_pos_callback);
    glfwSetCursorPosCallback(window_, window_cursor_pos_callback);
    glfwSetMouseButtonCallback(window_, window_mouse_button_callback);
    glfwSetWindowFocusCallback(window_, window_focus_callback);
    */
    return WindowBase::PostCreate(params);
}

void SdlWindow::SetQuitOnClose(bool quit_on_close)
{
    quit_on_close_ = quit_on_close;
}

bool SdlWindow::DoRun(RunParams params)
{

    SdlWindow::Point origin(10, 10);
    SdlWindow::Size size(1280, 720);

    bool success = CreateAndShow(params);

    assert(success);
    if (!success)
    {
        return false;
    }

    // Main loop
    bool done = false;
    while (!done)
    {
        {
            std::lock_guard<std::mutex> lk(mtx_);
            while (!q_.empty())
            {
                auto c = q_.front();
                q_.pop();
                if (c.kind == Cmd::Resize)
                    applyResize_(c.w, c.h);
            }
        }
        // glfwWaitEvents();
        // glfwPollEvents();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
                done = true;
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window_))
                done = true;
        }
        Render();
    }

    return WindowBase::DoRun(params);
}

bool SdlWindow::PostRun(RunParams params)
{
    Destroy();
    //glfwTerminate();
    return WindowBase::PostRun(params);
}

void SdlWindow::Destroy()
{
    //glfwDestroyWindow(window_);
    WindowBase::Destroy();
}

void SdlWindow::RequestResize(int w, int h)
{
    {
        std::lock_guard<std::mutex> lk(mtx_);
        q_.push({Cmd::Resize, w, h});
    }
    //glfwPostEmptyEvent(); // wake the window loop

    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_EVENT_USER;
    event.user.code = 0;
    event.user.data1 = nullptr;
    event.user.data2 = nullptr;
    SDL_PushEvent(&event);
}

void SdlWindow::applyResize_(int w, int h)
{
    // Single place that touches GLFW size; we’re on the window thread
    //glfwSetWindowSize(window_, w, h);
    SDL_SetWindowSize(window_, w, h);
}