#pragma once

#include <vector>

#include <fausty/config.h>
#include <fausty/rack/model.h>

namespace fausty {

class Control : public Model {
public:
  Control() : label_(nullptr), zone_(nullptr) {}
  Control(const char* label, fy_real* zone = nullptr) : label_(label), zone_(zone) {}
  //Data members
  const char* label_;
  fy_real* zone_;

  REFLECT_ENABLE(Model)
};

} // namespace fausty