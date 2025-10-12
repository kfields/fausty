#pragma once
#include "box_base.h"

class VBox : public BoxBase {
public:
  VBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};