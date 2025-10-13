#include "imgui.h"
#include "imnodes.h"

#include "module_widget.h"
#include <fausty/rack/module/module.h>

void ModuleWidget::Draw() {
  if (!DrawNode()) return;
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
  ImGui::Begin(model_->label_);
  DrawChildren();
  ImGui::End();
  ImGui::PopStyleVar();
}
bool ModuleWidget::DrawNode() {
  ImNodes::BeginNode(model_->id_);

  ImNodes::BeginNodeTitleBar();
  ImGui::TextUnformatted(model_->label_);
  ImNodes::EndNodeTitleBar();

  for (auto input : model_->inport_.pins_) {
    ImNodes::BeginInputAttribute(input->id_);
    ImGui::TextUnformatted(input->name_.c_str());
    ImNodes::EndInputAttribute();
  }

  for (auto output : model_->outport_.pins_) {
    ImNodes::BeginOutputAttribute(output->id_);
    ImGui::Indent(40);
    ImGui::TextUnformatted(output->name_.c_str());
    ImNodes::EndOutputAttribute();
  }

  ImNodes::EndNode();

  return true;
}

DEFINE_WIDGET(ModuleWidget, Module)
