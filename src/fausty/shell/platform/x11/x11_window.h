#pragma once

#include <functional>
#include <memory>
#include <string>

#include <fausty/shell/base_window.h>

namespace fausty
{

  class X11Window : public BaseWindow
  {
  public:
    X11Window();
    virtual ~X11Window();
    void NativeAttachTo(void *nativeParent) override;
  };

} // namespace fausty