//#include <GLFW/glfw3.h>
// GLFW + native X11 access
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>


#include "x11_window.h"

X11Window::X11Window()
{
}

X11Window::~X11Window()
{
    Destroy();
}

void X11Window::NativeAttachTo(void *nativeParent)
{
    //is_embedded_ = (nativeParent != nullptr);

    Display *dpy = glfwGetX11Display();
    ::Window child = glfwGetX11Window(window_);

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

    auto new_parent = (::Window)nativeParent;
    // Do the reparent
    XReparentWindow(dpy, child, new_parent, 0, 0);

    // Remap and flush
    XMapWindow(dpy, child);
    XFlush(dpy);
}