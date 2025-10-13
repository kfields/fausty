#pragma once

#include <fausty/part.h>

namespace fausty {

class Pin;
class Subscription;

class Wire : public Part {
public:
  Wire(Pin& output, Pin& input);
  //Data members
  Pin* input_ = nullptr;
  Pin* output_ = nullptr;
  Subscription* subscription_ = nullptr;
};

} // namespace fausty