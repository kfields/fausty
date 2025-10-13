#include "window.h"
#include "imgui.h"

void WindowBase::DestroyContext()
{
  system_container_.Destroy();
}
