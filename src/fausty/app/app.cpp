#include "implot.h"
#include "imnodes.h"

#include "../widget/widget_manager.h"

#include "../system/imgui_system.h"
#include "../system/implot_system.h"
#include "../system/imnodes_system.h"

#include "app.h"


bool App::booted_ = false;

App::App()
{
  Boot();
};

void App::Boot() {
  if (booted_) return;
  booted_ = true;

  REGISTER_WIDGET_FACTORY(RackWidget)
  REGISTER_WIDGET_FACTORY(ModuleWidget)
  REGISTER_WIDGET_FACTORY(ButtonWidget)
  REGISTER_WIDGET_FACTORY(CheckButtonWidget)
  REGISTER_WIDGET_FACTORY(VBoxWidget)
  REGISTER_WIDGET_FACTORY(HBoxWidget)
  REGISTER_WIDGET_FACTORY(NumEntryWidget)
  REGISTER_WIDGET_FACTORY(HSliderWidget)
  REGISTER_WIDGET_FACTORY(VSliderWidget)
  REGISTER_WIDGET_FACTORY(HBarGraphWidget)
  REGISTER_WIDGET_FACTORY(KnobWidget)
}

bool App::DoCreate(CreateParams params) {
    Window::DoCreate(params);
    CreateContext();
    return true;
}

void App::CreateContext()
{
  system_container_.Add(new ImGuiSystem());
  system_container_.Add(new ImPlotSystem());
  system_container_.Add(new ImNodesSystem());
  system_container_.Create();
}

/*
void App::Destroy()
{
  DestroyContext();
}

void App::DestroyContext()
{
  system_container_.Destroy();
}
*/

/*
void App::CreateContext()
{
  //WindowBase::CreateContext();
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  // Setup Dear ImGui context

  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
  // TODO: There's a memory leak involving viewports + glfw + OpenGL.
  // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

  // io.ConfigViewportsNoAutoMerge = true;
  // io.ConfigViewportsNoTaskBarIcon = true;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsClassic();

  // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
  ImGuiStyle &style = ImGui::GetStyle();
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
  {
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }

  ImPlot::CreateContext();
  ImNodes::CreateContext();
  // TODO:Move further down?
  ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkDetachWithDragClick);

  ImNodesIO &nodes_io = ImNodes::GetIO();
  nodes_io.LinkDetachWithModifierClick.Modifier = &ImGui::GetIO().KeyCtrl;
}

void App::DestroyContext()
{
  //Window::DestroyContext();
  ImGui::DestroyContext();
  ImPlot::DestroyContext();
  ImNodes::DestroyContext();
}
*/