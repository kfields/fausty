#pragma once

#include "widget.h"

class Module;

class ModuleWidget : public WidgetT<Module> {
public:
  ModuleWidget(Module& model) : WidgetT<Module>(model) {}
  void Draw() override;
  virtual bool DrawNode();
  DECLARE_WIDGET(ModuleWidget, Module)
};
