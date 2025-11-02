#pragma once

#include <map>

#include "model_view.h"

namespace fausty {

class Rack;

class RackView : public ModelViewT<Rack> {
public:
    RackView(Rack &rack);
    ~RackView();
    void Build() override;
    void PopulateWidgetMap(Widget *widget);

    void Draw() override;
    void DrawModuleCatalog();

    void BeginMainDockspace();

    void CheckLinkCreated();
    void CheckLinkDestroyed();
    void CheckCreateNode();

    void CheckMouse();

private:
    void LoadEditorState();
    void SaveEditorState();

    // Data members
    std::map<int, Widget *> widget_map_;
    int hovered_node_id = -1;
    int pending_link_start_attr = -1;
    ImVec2 pending_spawn_pos = ImVec2(0, 0);

};

} // namespace fausty