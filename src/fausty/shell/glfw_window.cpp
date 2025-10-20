#include <GLFW/glfw3.h>

#include "glfw_window.h"

static void glfw_error_callback(int error, const char *description)
{
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

GlfwWindow::GlfwWindow()
{
}

GlfwWindow::~GlfwWindow()
{
  Destroy();
}

// Event routing
void window_refresh_callback(GLFWwindow *win)
{
  GlfwWindow &window = *((GlfwWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowRefresh();
}
void window_size_callback(GLFWwindow *win, int width, int height)
{
  GlfwWindow &window = *((GlfwWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowSize(width, height);
}
void window_pos_callback(GLFWwindow *win, int xpos, int ypos)
{
  GlfwWindow &window = *((GlfwWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowPos(xpos, ypos);
}
void window_cursor_pos_callback(GLFWwindow *win, double x, double y)
{
  GlfwWindow &window = *((GlfwWindow *)glfwGetWindowUserPointer(win));
  window.OnCursorPos(x, y);
}
void window_mouse_button_callback(GLFWwindow *win, int button, int action, int mods)
{
  GlfwWindow &window = *((GlfwWindow *)glfwGetWindowUserPointer(win));
  window.OnMouseButton(button, action, mods);
}
void window_focus_callback(GLFWwindow *win, int focused)
{
  GlfwWindow &window = *((GlfwWindow *)glfwGetWindowUserPointer(win));
  window.OnWindowFocus(focused);
}

bool GlfwWindow::DoCreate(CreateParams params)
{
  WindowBase::DoCreate(params);
  // CreateContext();

  // Setup window
  glfwSetErrorCallback(glfw_error_callback);

  if (!glfwInit())
    return false;

  // Create window with graphics context
  
  is_embedded_ = (params.nativeParent != nullptr);

  if (is_embedded_)
  {
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
  }

  window_ = glfwCreateWindow(1280, 720, "Fausty!", NULL, NULL);
  
  if (window_ == NULL)
    return false;

  if (params.nativeParent)
  {
    NativeAttachTo(params.nativeParent);
  }
  //glfwSetInputMode(window_, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
  //glfwSetWindowAttrib(window_, GLFW_MOUSE_PASSTHROUGH, GLFW_FALSE);

  glfwMakeContextCurrent(window_);
  glfwSwapInterval(1); // Enable vsync

  glfwSetWindowUserPointer(window_, this);
  
  glfwSetWindowRefreshCallback(window_, window_refresh_callback);
  glfwSetWindowSizeCallback(window_, window_size_callback);
  glfwSetWindowPosCallback(window_, window_pos_callback);
  glfwSetCursorPosCallback(window_, window_cursor_pos_callback);
  glfwSetMouseButtonCallback(window_, window_mouse_button_callback);
  glfwSetWindowFocusCallback(window_, window_focus_callback);

  return true;
}

bool GlfwWindow::PostCreate(CreateParams params)
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

void GlfwWindow::SetQuitOnClose(bool quit_on_close)
{
  quit_on_close_ = quit_on_close;
}

bool GlfwWindow::DoRun(RunParams params)
{

  GlfwWindow::Point origin(10, 10);
  GlfwWindow::Size size(1280, 720);

  bool success = CreateAndShow(params);

  assert(success);
  if (!success)
  {
    return false;
  }

  // Main loop
  while (!glfwWindowShouldClose(window_))
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
    glfwWaitEvents();
    //glfwPollEvents();
    Render();
  }

  return WindowBase::DoRun(params);
}

bool GlfwWindow::PostRun(RunParams params)
{
  Destroy();
  glfwTerminate();
  return WindowBase::PostRun(params);
}

void GlfwWindow::Destroy()
{
  glfwDestroyWindow(window_);
  WindowBase::Destroy();
}

void GlfwWindow::RequestResize(int w, int h)
{
  {
    std::lock_guard<std::mutex> lk(mtx_);
    q_.push({Cmd::Resize, w, h});
  }
  glfwPostEmptyEvent(); // wake the window loop
}

void GlfwWindow::applyResize_(int w, int h)
{
  // Single place that touches GLFW size; we’re on the window thread
  glfwSetWindowSize(window_, w, h);
}