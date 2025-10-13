#pragma once
#include "box_base.h"

namespace fausty {

class TabBox : public BoxBase {
public:
  TabBox(const char* label) : BoxBase(label) {}

  REFLECT_ENABLE(BoxBase)
};

} // namespace fausty