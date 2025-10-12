#include <GLFW/glfw3.h>

#include "x11_window.h"


X11Window::X11Window() {
}

X11Window::~X11Window() {
    Destroy();
}
