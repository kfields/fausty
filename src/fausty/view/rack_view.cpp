#include "imgui.h"
#include "imnodes.h"

#include "rack_view.h"
#include <fausty/rack/rack.h>
#include <fausty/rack/pin.h>
#include <fausty/rack/wire.h>

namespace fausty {

RackView::RackView(Rack &rack) : ModelViewT<Rack>(rack)
{
  //LoadEditorState();
}

RackView::~RackView()
{
  //SaveEditorState();
  if (root_)
  {
    delete root_;
    root_ = nullptr;
  }
}

void RackView::LoadEditorState()
{
  ImNodes::LoadCurrentEditorStateFromIniFile("imnodes.ini");
}

void RackView::SaveEditorState()
{
  ImNodes::SaveCurrentEditorStateToIniFile("imnodes.ini");
}

void RackView::Draw()
{
  if (root_ == nullptr)
  {
    Build();
  }
  ImGui::Begin("Rack Graph");

  ImNodes::BeginNodeEditor();

  root_->Draw();

  for (auto wire : model_->wires_)
  {
    ImNodes::Link(wire->id_, wire->output_->id_, wire->input_->id_);
  }

  ImNodes::EndNodeEditor();

  int startId, endId;
  bool createdFromSnap;
  if (ImNodes::IsLinkCreated(&startId, &endId, &createdFromSnap))
  {
    Pin &output = *model_->output_map_[startId];
    Pin &input = *model_->input_map_[endId];
    model_->Connect(output, input);
  }

  int linkId;
  if (ImNodes::IsLinkDestroyed(&linkId))
  {
    auto wire = model_->wire_map_[linkId];
    model_->Disconnect(*wire);
  }
  ImGui::End();
}

} // namespace fausty