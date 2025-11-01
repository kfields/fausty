#pragma once

#include "widget.h"

namespace fausty {

class Module;

class ModuleWidget : public WidgetT<Module> {
public:
    ModuleWidget(Module &model) : WidgetT<Module>(model) {}
    void Draw() override;
    virtual bool DrawNode();
    virtual bool DrawWindow();

    void ShowWindow() { is_open_ = true; }
    void HideWindow() { is_open_ = false; }
    
    DECLARE_WIDGET(ModuleWidget, Module)

    // Data members
    bool is_open_ = false;
};

} // namespace fausty