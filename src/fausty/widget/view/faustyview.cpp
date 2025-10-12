#include "faustyview.h"
#include "../widget_manager.h"

bool FaustyView::booted_ = false;

void FaustyView::Boot() {
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