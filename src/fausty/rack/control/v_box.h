#pragma once
#include "box_base.h"

namespace fausty {

class VBox : public BoxBase {
public:
  VBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};

} // namespace fausty