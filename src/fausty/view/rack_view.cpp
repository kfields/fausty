#include "imgui.h"
#include "imgui_internal.h"

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

    BeginMainDockspace();

    ImGuiWindowFlags graph_flags =
    ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoScrollWithMouse |
    ImGuiWindowFlags_NoBringToFrontOnFocus; // <-- key

    ImGui::Begin("Graph", nullptr, graph_flags);

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
            if (const auto it = widget_map_.find(hovered_node_id); it != widget_map_.end()) {
                Widget* widget = it->second;
                if (auto* module_widget = dynamic_cast<ModuleWidget*>(widget)) {
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

static bool s_built_dock = false;

void RackView::BeginMainDockspace()
{
    ImGuiWindowFlags host_flags =
        ImGuiWindowFlags_NoDocking |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoNavFocus |
        ImGuiWindowFlags_NoBackground; // optional, keeps it invisible

    ImGuiViewport* vp = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(vp->WorkPos);
    ImGui::SetNextWindowSize(vp->WorkSize);
    ImGui::SetNextWindowViewport(vp->ID);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

    ImGui::Begin("DockHost", nullptr, host_flags);

    ImGui::PopStyleVar(3);

    // Create a dockspace filling this host window
    ImGuiID dockspace_id = ImGui::GetID("MainDockspace");
    ImGuiDockNodeFlags dock_flags = ImGuiDockNodeFlags_PassthruCentralNode; // central node draws your windows
    ImGui::DockSpace(dockspace_id, ImVec2(0, 0), dock_flags);

    // Build default layout once
    if (!s_built_dock)
    {
        s_built_dock = true;

        ImGui::DockBuilderRemoveNode(dockspace_id);
        ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
        ImGui::DockBuilderSetNodeSize(dockspace_id, vp->WorkSize);

        ImGuiID dock_main_id = dockspace_id;
        ImGuiID dock_right, dock_bottom;
        dock_right  = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Right, 0.25f, nullptr, &dock_main_id);
        dock_bottom = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Down,  0.30f, nullptr, &dock_main_id);

        ImGui::DockBuilderDockWindow("Graph",     dock_main_id);   // central
        ImGui::DockBuilderDockWindow("Inspector", dock_right);     // right
        ImGui::DockBuilderDockWindow("Console",   dock_bottom);    // bottom
        ImGui::DockBuilderFinish(dockspace_id);
    }

    ImGui::End(); // DockHost
}

} // namespace fausty