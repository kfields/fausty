#include "faustyapp.h"
#include "app.h"

#include "implot.h"
#include "imnodes.h"

App::App() {
  FaustyApp::Boot();
};

void App::CreateContext() {
  WindowBase::CreateContext();
  ImPlot::CreateContext();
  ImNodes::CreateContext();
  //TODO:Move further down?
  ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkDetachWithDragClick);

  ImNodesIO& io = ImNodes::GetIO();
  io.LinkDetachWithModifierClick.Modifier = &ImGui::GetIO().KeyCtrl;
}
void App::DestroyContext() {
  WindowBase::DestroyContext();
  ImPlot::DestroyContext();
  ImNodes::DestroyContext();
}

