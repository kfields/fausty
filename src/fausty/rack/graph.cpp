#include "graph.h"
#include "wire.h"
#include "pin.h"

namespace fausty {

void Graph::AddOutput(Pin& output) { output_map_[output.id_] = &output; }

void Graph::AddInput(Pin& input) { input_map_[input.id_] = &input; }

void Graph::Connect(Pin& output, Pin& input) {
  auto wire = new Wire(output, input);
  wires_.push_back(wire);
  wire_map_[wire->id_] = wire;
}

void Graph::Disconnect(Wire& wire) {
  wires_.remove(&wire);
  wire_map_.erase(wire.id_);
}

} // namespace fausty