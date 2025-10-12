#pragma once
#include "button_base.h"

class Button : public ButtonBase {
public:
  Button(const char* label, fy_real* zone) : ButtonBase(label, zone) {}

  REFLECT_ENABLE(ButtonBase)
};