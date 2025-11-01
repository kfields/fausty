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

private:
    void LoadEditorState();
    void SaveEditorState();

    // Data members
    std::map<int, Widget *> widget_map_;
    int hovered_node_id = -1;
};

} // namespace fausty