#include "imgui.h"

#include "widget.h"
#include <fausty/rack/control/v_slider.h>

namespace fausty {

class VSliderWidget : public WidgetT<VSlider> {
public:
  VSliderWidget(VSlider& model) : WidgetT<VSlider>(model) {}
  void Draw() override {
    ImVec2 size(64, 128);
    ImGui::VSliderFloat(model_->label_, size, model_->zone_, model_->min_, model_->max_);
  }
};
DEFINE_WIDGET_FACTORY(VSliderWidget, VSlider)

} // namespace fausty