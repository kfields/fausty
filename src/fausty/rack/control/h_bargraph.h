#pragma once
#include "bargraph_base.h"

namespace fausty {

class HBarGraph : public BarGraphBase {
public:
  HBarGraph(const char* label, fy_real* zone, fy_real min, fy_real max) : BarGraphBase(label, zone, min, max) {}

  REFLECT_ENABLE(BarGraphBase)
};

} // namespace fausty