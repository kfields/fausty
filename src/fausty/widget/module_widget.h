#pragma once

#include "widget.h"

namespace fausty {

class Module;

class ModuleWidget : public WidgetT<Module> {
public:
  ModuleWidget(Module& model) : WidgetT<Module>(model) {}
  void Draw() override;
  virtual bool DrawNode();
  DECLARE_WIDGET(ModuleWidget, Module)
};

} // namespace fausty