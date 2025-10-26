#include <string>
#include <cassert>
#include <chrono>
#include <iostream>
#include <filesystem>

#include <fausty/shell/shell.h>

#include "app.h"

#include "rackeditor_impl.h"
#include "rackview_impl.h"

RackViewImpl::RackViewImpl(PannerEditor *editor, ViewRect *size)
    : PannerView(editor, size)
{
}

tresult PLUGIN_API RackViewImpl::attached(void *parent, FIDString type)
{

    std::cout << "RackViewImpl::attached" << std::endl
              << std::flush;

    parent_ = parent;

    app_ = new MyApp();

    // Release any current context on this (host) thread
    //glfwMakeContextCurrent(nullptr);

    running_ = true;
    renderThread_ = std::thread([this]()
                                { this->Run(); });
    return RackView::attached(parent, type);
}

void RackViewImpl::Run()
{
    const fausty::Window::RunParams runParams("", fausty::Window::Point(0, 0),
                                        fausty::Window::Size(rect.getWidth(), rect.getHeight()),
                                        parent_);
    app_->Run(runParams);
}

tresult PLUGIN_API RackViewImpl::removed()
{
    app_->Destroy();
    return RackView::removed();
}

tresult PLUGIN_API RackViewImpl::onSize(ViewRect *newSize)
{
    if (app_ == nullptr)
        return RackView::onSize(newSize);

    int w = newSize->getWidth();
    int h = newSize->getHeight();
    std::cout << "RackViewImpl::onSize " << w << "x" << h << std::endl
              << std::flush;
    app_->RequestResize(w, h);
    return RackView::onSize(newSize);
}
