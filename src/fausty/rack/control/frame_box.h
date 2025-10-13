#pragma once
#include "box_base.h"

namespace fausty {

class FrameBox : public BoxBase {
public:
  FrameBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};

} // namespace fausty