#pragma once

#include <functional>
#include <memory>
#include <string>

#include <fausty/shell/sdl_window.h>

class X11Window : public SdlWindow
{
public:
  X11Window();
  virtual ~X11Window();
  void NativeAttachTo(void *nativeParent) override;
};
