#include "imgui.h"

#include "widget.h"
#include <fausty/rack/control/h_slider.h>

namespace fausty {

class HSliderWidget : public WidgetT<HSlider> {
public:
  HSliderWidget(HSlider& model) : WidgetT<HSlider>(model) {}
  void Draw() override {
    ImGui::SliderFloat(model_->label_, model_->zone_, model_->min_, model_->max_);
  }
  DECLARE_WIDGET(HSliderWidget, HSlider)
};
DEFINE_WIDGET(HSliderWidget, HSlider)

} // namespace fausty