#include "imnodes.h"

#include "imnodes_context.h"


void ImNodesContext::Create() {
  ImNodes::CreateContext();
  ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkDetachWithDragClick);

  ImNodesIO &io = ImNodes::GetIO();
  io.LinkDetachWithModifierClick.Modifier = &ImGui::GetIO().KeyCtrl;

}

void ImNodesContext::Destroy() {
  ImNodes::DestroyContext();
}