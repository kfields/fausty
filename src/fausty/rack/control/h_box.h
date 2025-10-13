#pragma once
#include "box_base.h"

namespace fausty {

class HBox : public BoxBase {
public:
  HBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};

} // namespace fausty