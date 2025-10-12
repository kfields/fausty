#pragma once
#include "control.h"

class ButtonBase : public Control {
public:
  ButtonBase(const char* label, fy_real* zone) : Control(label, zone) {}

  REFLECT_ENABLE(Control)
};