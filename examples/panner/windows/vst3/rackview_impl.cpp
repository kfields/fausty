#include <string>
#include <cassert>
#include <chrono>
#include <iostream>
#include <filesystem>

#include <windows.h>

#include <fausty/shell/shell.h>
#include <fausty/shell/platform/windows/utils.h>

#include "app.h"

#include "rackeditor_impl.h"
#include "rackview_impl.h"

RackViewImpl::RackViewImpl(PannerEditor* editor, ViewRect* size)
    : PannerView(editor, size)
{
}

tresult PLUGIN_API RackViewImpl::attached(void* parent, FIDString type)
{
    HWND hParent = (HWND)parent;

    // Attach to console when present (e.g., 'flutter run') or create a
    // new console when running with a debugger.
    //if (!::AttachConsole(ATTACH_PARENT_PROCESS) && ::IsDebuggerPresent()) {
        //CreateAndAttachConsole();
    //}
    std::cout << "RackViewImpl::attached" << std::endl << std::flush;

    // Initialize COM, so that it is available for use in the library and/or
    // plugins.
    HRESULT hResult = ::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    window_ = new MyApp();
    Window& window = *window_;
    window.AttachTo((HWND)parent);
    return RackView::attached(parent, type);
}

void RackViewImpl::Run() {
    //run_loop_.Run();
}
tresult PLUGIN_API RackViewImpl::removed() {
  window_->Destroy();
  ::CoUninitialize();
  return RackView::removed();
}
tresult PLUGIN_API RackViewImpl::onSize(ViewRect* newSize)
{
    if (window_ != nullptr) {
        HWND hWnd = window_->GetHandle();
        int width = newSize->getWidth();
        int height = newSize->getHeight();
        std::cout << "onSize " << width << " " << height << std::endl << std::flush;
        MoveWindow(hWnd, 0, 0, width, height, true);
    }
    return RackView::onSize(newSize);
}