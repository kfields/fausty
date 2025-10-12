#pragma once
#include "box_base.h"

class HBox : public BoxBase {
public:
  HBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};