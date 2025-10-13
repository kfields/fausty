#include <string>
#include <cassert>
#include <chrono>
#include <iostream>
#include <filesystem>

// GLFW + native X11 access
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>

#include <fausty/shell/shell.h>
// #include <fausty/shell/platform/windows/utils.h>

#include "app.h"

#include "rackeditor_impl.h"
#include "rackview_impl.h"

RackViewImpl::RackViewImpl(PannerEditor *editor, ViewRect *size)
    : PannerView(editor, size)
{
}

tresult PLUGIN_API RackViewImpl::attached(void *parent, FIDString type)
{

    // HWND hParent = (HWND)parent;
    auto new_parent = (::Window)parent;

    // Attach to console when present (e.g., 'flutter run') or create a
    // new console when running with a debugger.
    // if (!::AttachConsole(ATTACH_PARENT_PROCESS) && ::IsDebuggerPresent()) {
    // CreateAndAttachConsole();
    //}
    std::cout << "RackViewImpl::attached" << std::endl
              << std::flush;

    window_ = new MyApp();
    fausty::Window &window = *window_;
    // window.AttachTo((HWND)parent);

    Display *dpy = glfwGetX11Display();
    ::Window child = glfwGetX11Window(window.window_);

    // Unmap to avoid flicker and let the server update hierarchy cleanly
    XUnmapWindow(dpy, child);

    // Do the reparent
    XReparentWindow(dpy, child, new_parent, 0, 0);

    // Remap and flush
    XMapWindow(dpy, child);
    XFlush(dpy);

    return RackView::attached(parent, type);
}

void RackViewImpl::Run()
{
    // run_loop_.Run();
}
tresult PLUGIN_API RackViewImpl::removed()
{
    window_->Destroy();
    return RackView::removed();
}
tresult PLUGIN_API RackViewImpl::onSize(ViewRect *newSize)
{
    /*
    if (window_ != nullptr) {
        HWND hWnd = window_->GetHandle();
        int width = newSize->getWidth();
        int height = newSize->getHeight();
        std::cout << "onSize " << width << " " << height << std::endl << std::flush;
        MoveWindow(hWnd, 0, 0, width, height, true);
    }
    */

    return RackView::onSize(newSize);
}