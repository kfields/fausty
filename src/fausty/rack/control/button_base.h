#pragma once
#include "control.h"

namespace fausty {

class ButtonBase : public Control {
public:
  ButtonBase(const char* label, fy_real* zone) : Control(label, zone) {}

  REFLECT_ENABLE(Control)
};

} // namespace fausty