#pragma once

#include <functional>
#include <memory>
#include <string>

#include <fausty/shell/base_window.h>

class X11Window : public BaseWindow
{
public:
  X11Window();
  virtual ~X11Window();
  void NativeAttachTo(void *nativeParent) override;
};
