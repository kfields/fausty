#pragma once
#include "box_base.h"

class FrameBox : public BoxBase {
public:
  FrameBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};