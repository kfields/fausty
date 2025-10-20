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

    parent_ = parent;

    app_ = new MyApp();

    /*
    app_->Create();

    fausty::App &app = *app_;
    // window.AttachTo((HWND)parent);

    Display *dpy = glfwGetX11Display();
    ::Window child = glfwGetX11Window(app.window_);

    // Unmap to avoid flicker and let the server update hierarchy cleanly
    XUnmapWindow(dpy, child);

    // Do the reparent
    XReparentWindow(dpy, child, new_parent, 0, 0);

    // Remap and flush
    XMapWindow(dpy, child);
    XFlush(dpy);
    */

    // Release any current context on this (host) thread
    glfwMakeContextCurrent(nullptr);

    running_ = true;
    renderThread_ = std::thread([this]()
                                { this->Run(); });
    return RackView::attached(parent, type);
}

void RackViewImpl::Run()
{
    app_->Create();

    fausty::App &app = *app_;
    // window.AttachTo((HWND)parent);

    Display *dpy = glfwGetX11Display();
    ::Window child = glfwGetX11Window(app.window_);

    /*
    XSetWindowAttributes attributes;
    attributes.override_redirect = True;
    XChangeWindowAttributes(dpy, child, CWOverrideRedirect, &attributes);
    */

    /*
    // 1) Tell host we speak XEmbed
    Atom XEMBED_INFO = XInternAtom(dpy, "_XEMBED_INFO", False);
    // version=0, flags=1 (XEMBED_MAPPED) — see XEmbed spec
    unsigned long xembed_data[2] = {0, 1};
    XChangeProperty(dpy, child, XEMBED_INFO, XEMBED_INFO, 32, PropModeReplace,
                    reinterpret_cast<const unsigned char *>(xembed_data), 2);
    */

    // Unmap to avoid flicker and let the server update hierarchy cleanly
    XUnmapWindow(dpy, child);

    auto new_parent = (::Window)parent_;
    // Do the reparent
    XReparentWindow(dpy, child, new_parent, 0, 0);

    // Remap and flush
    XMapWindow(dpy, child);
    XFlush(dpy);

    /*
    // Add the masks ImGui needs for drag/collapse/titlebar ops
    long mask = ExposureMask | StructureNotifyMask | FocusChangeMask |
                ButtonPressMask | ButtonReleaseMask |
                PointerMotionMask | ButtonMotionMask |
                EnterWindowMask | LeaveWindowMask;
    XSelectInput(dpy, child, mask);
    XFlush(dpy);

    // Make sure we actually have keyboard focus
    XSetInputFocus(dpy, child, RevertToParent, CurrentTime);
    XFlush(dpy);
    */

    glfwMakeContextCurrent(app_->window_);
    app_->Run();
}

tresult PLUGIN_API RackViewImpl::removed()
{
    app_->Destroy();
    return RackView::removed();
}

tresult PLUGIN_API RackViewImpl::onSize(ViewRect *newSize)
{
    if (app_ == nullptr)
        return RackView::onSize(newSize);

    int w = newSize->getWidth();
    int h = newSize->getHeight();
    std::cout << "RackViewImpl::onSize " << w << "x" << h << std::endl
              << std::flush;
    app_->RequestResize(w, h);
    return RackView::onSize(newSize);
}
