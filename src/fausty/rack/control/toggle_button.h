#pragma once
#include "button_base.h"

namespace fausty {

class ToggleButton : public ButtonBase {
public:
  ToggleButton(const char* label, fy_real* zone) : ButtonBase(label, zone) {}

  REFLECT_ENABLE(ButtonBase)
};

} // namespace fausty