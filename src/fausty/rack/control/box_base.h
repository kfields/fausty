#pragma once
#include "control.h"

namespace fausty {

class BoxBase : public Control {
public:
  BoxBase(const char* label) : Control(label) {}
  //Data members

  REFLECT_ENABLE(Control)
};

} // namespace fausty