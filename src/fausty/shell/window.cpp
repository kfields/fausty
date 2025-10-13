#include "window.h"
#include "imgui.h"

/*
bool WindowBase::DoCreate(CreateParams params) {
    //CreateContext();
    return true;
}
*/

/*
void WindowBase::CreateContext() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
}

void WindowBase::DestroyContext() {
  ImGui::DestroyContext();
}
*/
void WindowBase::DestroyContext()
{
  system_container_.Destroy();
}
