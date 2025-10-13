#include "implot.h"
#include "imnodes.h"

#include "../widget/widget_manager.h"

#include "../system/imgui_system.h"
#include "../system/implot_system.h"
#include "../system/imnodes_system.h"

#include "app.h"

namespace fausty {

bool App::booted_ = false;

App::App()
{
  Boot();
};

void App::Boot() {
  if (booted_) return;
  booted_ = true;

  REGISTER_WIDGET_FACTORY(RackWidget)
  REGISTER_WIDGET_FACTORY(ModuleWidget)
  REGISTER_WIDGET_FACTORY(ButtonWidget)
  REGISTER_WIDGET_FACTORY(CheckButtonWidget)
  REGISTER_WIDGET_FACTORY(VBoxWidget)
  REGISTER_WIDGET_FACTORY(HBoxWidget)
  REGISTER_WIDGET_FACTORY(NumEntryWidget)
  REGISTER_WIDGET_FACTORY(HSliderWidget)
  REGISTER_WIDGET_FACTORY(VSliderWidget)
  REGISTER_WIDGET_FACTORY(HBarGraphWidget)
  REGISTER_WIDGET_FACTORY(KnobWidget)
}

void App::CreateContext()
{
  system_container_.Add(new ImGuiSystem());
  system_container_.Add(new ImPlotSystem());
  system_container_.Add(new ImNodesSystem());
  system_container_.Create();
}

} // namespace fausty