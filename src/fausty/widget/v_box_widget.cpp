#include "imgui.h"

#include "widget.h"
#include <fausty/rack/control/v_box.h>

namespace fausty {

class VBoxWidget : public WidgetT<VBox> {
public:
  VBoxWidget(VBox& model) : WidgetT<VBox>(model) {}
  void Draw() override {
    if (ImGui::TreeNode(model_->label_)) {
      ImGui::BeginGroup();
      DrawChildren();
      ImGui::EndGroup();
      ImGui::TreePop();
      ImGui::Separator();
    }
  }
};
DEFINE_WIDGET_FACTORY(VBoxWidget, VBox)

} // namespace fausty