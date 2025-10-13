#pragma once

#include "model_view.h"

class Rack;

class RackView : public ModelViewT<Rack> {
public:
  RackView(Rack& rack);
  ~RackView();
  void Draw() override;
private:
  void LoadEditorState();
  void SaveEditorState();
};