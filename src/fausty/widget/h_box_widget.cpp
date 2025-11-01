#include "imgui.h"

#include "widget.h"
#include <fausty/rack/control/h_box.h>

namespace fausty {

class HBoxWidget : public WidgetT<HBox> {
public:
  HBoxWidget(HBox& model) : WidgetT<HBox>(model) {}
  void Draw() override {
    ImGui::BeginGroup();
    //ImGui::PushItemWidth(128);
    DrawChildren();
    //ImGui::PopItemWidth();
    ImGui::EndGroup();
  }
  virtual void DrawChild(Widget& child) override {
    if(children_.back() != &child)
      ImGui::SameLine();

    child.Draw();
    /*
    if(children_.back() != &child)
      ImGui::SameLine();
    */
  }
  DECLARE_WIDGET(HBoxWidget, HBox)
};
DEFINE_WIDGET(HBoxWidget, HBox)

} // namespace fausty