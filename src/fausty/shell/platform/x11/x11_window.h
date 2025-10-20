#pragma once

#include <functional>
#include <memory>
#include <string>

#include <fausty/shell/glfw_window.h>

class X11Window : public GlfwWindow
{
public:
  X11Window();
  virtual ~X11Window();
  void NativeAttachTo(void *nativeParent) override;
};
