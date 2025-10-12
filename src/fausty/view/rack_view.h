#pragma once

#include "model_view.h"

class Rack;

class RackView : public ModelViewT<Rack> {
public:
  RackView(Rack& rack) : ModelViewT<Rack>(rack) {}
  void Draw() override;
};