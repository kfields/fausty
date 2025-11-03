#include "imgui.h"

#include "box_widget.h"
#include <fausty/rack/control/h_box.h>

namespace fausty {

class HBoxWidget : public BoxWidgetT<HBox> {
public:
    HBoxWidget(HBox &model) : BoxWidgetT<HBox>(model) {}
    void Draw() override {
        // ImGui::Text("%s", model_->label_);
        //ImGui::SeparatorText(model_->label_);
        DrawHeader();
        ImGui::BeginGroup();
        DrawChildren();
        ImGui::EndGroup();
    }
    virtual void DrawChild(Widget &child) override {
        child.Draw();

        if (children_.back() != &child)
            ImGui::SameLine();
    }
};
DEFINE_WIDGET_FACTORY(HBoxWidget, HBox)

} // namespace fausty