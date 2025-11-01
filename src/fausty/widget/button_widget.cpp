#include "imgui.h"

#include "widget.h"
#include <fausty/rack/control/button.h>

namespace fausty {

class ButtonWidget : public WidgetT<Button> {
public:
  ButtonWidget(Button& model) : WidgetT<Button>(model) {}
  void Draw() override {
    if (ImGui::Button(model_->label_)) {
      *model_->zone_ = 1.0;
    }
    else {
      *model_->zone_ = 0.0;
    }
  }
};
DEFINE_WIDGET_FACTORY(ButtonWidget, Button)

} // namespace fausty