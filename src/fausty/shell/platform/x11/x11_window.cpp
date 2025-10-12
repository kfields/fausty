#include <GLFW/glfw3.h>

#include "x11_window.h"


X11Window::X11Window() {
}

X11Window::~X11Window() {
    paint_thread_.detach();
    Destroy();
}

/*
RECT X11Window::GetClientArea() {
  RECT frame;
  GetClientRect(GetHandle(), &frame);
  return frame;
}

HWND X11Window::GetHandle() {
  return glfwGetX11Window(window_);
}

int X11Window::AttachTo(HWND hParent) {
  WindowBase::Point origin(10, 10);
  WindowBase::Size size(1280, 720);
  bool success = CreateAndShow(CreateParams("NoName", origin, size));
  assert(success);
  if (!success) {
    return 1;
  }
  HWND hWnd = GetHandle();
  SetParent(hWnd, hParent);
  const LONG nNewStyle = (GetWindowLong(hWnd, GWL_STYLE) & ~WS_POPUP & ~WS_OVERLAPPEDWINDOW) | WS_CHILDWINDOW | WS_VISIBLE;
  SetWindowLong(hWnd, GWL_STYLE, nNewStyle);
  const ULONG_PTR cNewStyle = GetClassLongPtr(hWnd, GCL_STYLE) | CS_DBLCLKS;
  SetClassLongPtr(hWnd, GCL_STYLE, cNewStyle);
  ShowWindow(hWnd, SW_NORMAL);

  return 0;
}
*/

bool X11Window::PostCreate(WindowBase::CreateParams params) {
  /*HWND hwnd = GetHandle();
  paint_thread_ = std::thread([hwnd]() {
    RECT rc;
    GetClientRect(hwnd, &rc);
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(16));
      InvalidateRect(hwnd, &rc, true);
    }
    });*/

  return GlfwWindow::PostCreate(params);
}
