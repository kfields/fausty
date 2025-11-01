#include "imgui.h"
#include "imnodes.h"

#include "rack_view.h"
#include <fausty/widget/module_widget.h>

#include <fausty/rack/pin.h>
#include <fausty/rack/rack.h>
#include <fausty/rack/wire.h>
#include <fausty/rack/module/module.h>

namespace fausty {

RackView::RackView(Rack &rack) : ModelViewT<Rack>(rack) {}

RackView::~RackView() {
    if (root_) {
        delete root_;
        root_ = nullptr;
    }
}

void RackView::Build() {
    ModelView::Build();  // Call parent Build()
    
    // After build completes, traverse root_ and populate widget_map_
    if (root_) {
        PopulateWidgetMap(root_);
    }
}

// Helper to recursively populate widget_map_
void RackView::PopulateWidgetMap(Widget* widget) {
    if (!widget) return;
    
    if (widget->model()) {
        widget_map_[widget->model()->id_] = widget;
    }
    
    // Recursively process children
    for (auto* child : widget->children_) {
        PopulateWidgetMap(child);
    }
}

void RackView::LoadEditorState() {
    ImNodes::LoadCurrentEditorStateFromIniFile("imnodes.ini");
}

void RackView::SaveEditorState() {
    ImNodes::SaveCurrentEditorStateToIniFile("imnodes.ini");
}

void RackView::Draw() {
    if (root_ == nullptr) {
        Build();
    }
    ImGui::Begin("Rack Graph");

    ImNodes::BeginNodeEditor();

    root_->Draw();

    for (auto wire : model_->wires_) {
        ImNodes::Link(wire->id_, wire->output_->id_, wire->input_->id_);
    }

    ImNodes::EndNodeEditor();

    int startId, endId;
    bool createdFromSnap;
    if (ImNodes::IsLinkCreated(&startId, &endId, &createdFromSnap)) {
        Pin &output = *model_->output_map_[startId];
        Pin &input = *model_->input_map_[endId];
        model_->Connect(output, input);
    }

    int linkId;
    if (ImNodes::IsLinkDestroyed(&linkId)) {
        auto wire = model_->wire_map_[linkId];
        model_->Disconnect(*wire);
    }

    int node_id = -1;
    if (ImNodes::IsNodeHovered(&node_id)) {
        hovered_node_id = node_id;
        // Left double-click on a hovered node
        if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
            // handle double-click on hovered_node_id
            auto it = widget_map_.find(hovered_node_id);
            if (it != widget_map_.end()) {
                Widget* widget = it->second;
                ModuleWidget* module_widget = dynamic_cast<ModuleWidget*>(widget);
                if (module_widget) {
                    module_widget->is_open_ = !module_widget->is_open_;
                }
            }
        }

        // Right click on a hovered node
        if (ImGui::IsMouseClicked(ImGuiMouseButton_Right)) {
            // handle right-click on hovered_node_id
            // e.g. open a context menu:
            ImGui::OpenPopup("node_ctx");
        }
    }

    // Optional: context menu contents
    if (ImGui::BeginPopup("node_ctx")) {
        ImGui::Text("Node %d", hovered_node_id);
        if (ImGui::MenuItem("Do thing")) { /* ... */
        }
        ImGui::EndPopup();
    }

    ImGui::End();
}

} // namespace fausty