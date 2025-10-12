#include "pin.h"
#include "wire.h"

Wire::Wire(Pin& output, Pin& input) : output_(&output), input_(&input)
{
  input.AddWire(*this);
  output.AddWire(*this);

  subscription_ = output.Connect(input);
}
