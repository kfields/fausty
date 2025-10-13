#pragma once

#include "widget.h"

namespace fausty {

class Rack;

class RackWidget : public WidgetT<Rack> {
public:
  RackWidget(Rack& model) : WidgetT<Rack>(model) {}
  //virtual void Draw();
  DECLARE_WIDGET(RackWidget, Rack)
};

} // namespace fausty