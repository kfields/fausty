#pragma once

#include <functional>
#include <memory>
#include <string>

#include <windows.h>

#include <fausty/shell/glfw_window.h>

class Win32Window : public GlfwWindow
{
public:
  Win32Window();
  virtual ~Win32Window();
};
