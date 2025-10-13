#pragma once
#include "button_base.h"

namespace fausty {

class CheckButton : public ButtonBase {
public:
  CheckButton(const char* label, fy_real* zone) : ButtonBase(label, zone) {}

  REFLECT_ENABLE(ButtonBase)
};

} // namespace fausty