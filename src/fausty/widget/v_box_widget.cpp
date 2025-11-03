#include "imgui.h"

#include "box_widget.h"
#include <fausty/rack/control/v_box.h>

namespace fausty {

class VBoxWidget : public BoxWidgetT<VBox> {
public:
    VBoxWidget(VBox &model) : BoxWidgetT<VBox>(model) {}

    void Draw() override {
        ImGui::BeginGroup();
        //ImGui::SeparatorText(model_->label_);
        DrawHeader();
        DrawChildren();
        ImGui::EndGroup();
    }
/*
void Draw() override {
    if (ImGui::TreeNode(model_->label_)) {
        ImGui::BeginGroup();
        DrawChildren();
        ImGui::EndGroup();
        ImGui::TreePop();
        ImGui::Separator();
    }
}
*/
};
DEFINE_WIDGET_FACTORY(VBoxWidget, VBox)

} // namespace fausty