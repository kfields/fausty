#include <fausty/rack/rack.h>

#include "module.h"

bool Module::Create(Part& owner) {
  Node::Create(owner);
  Rack::instance().AddModule(*this);
  return true;
}