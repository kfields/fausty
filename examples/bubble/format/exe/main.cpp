#include <fausty/rack/format/exe/exe_rack.h>
#include <fausty/rack/module/module.h>
#include <fausty/rack/module/faust_dsp.h>
#include <fausty/rack/module/faust_dsp_ui.h>

#include <fausty/app/app.h>

#include <fausty/widget/widget.h>
#include <fausty/widget/widget_manufacturer.h>
#include <fausty/view/rack_view.h>

#include "bubble_dsp.h"

using namespace fausty;

class BubbleDspImpl : public BubbleDsp
{
public:
  REFLECT_ENABLE(BubbleDsp)
};

class MyApp : public App
{
public:
  MyApp()
  {
    BubbleDsp &m = ModelFactoryT<BubbleDspImpl>::Make(rack_);
    rack_.AddChild(m);
    view_ = new RackView(rack_);
  }

  void Draw() override
  {
    view_->Draw();
    App::Draw();
  }
  // Data members
  ExeRack rack_;
  RackView *view_;
};

int main(int, char **)
{
  MyApp &app = *new MyApp();
  ExeRack &rack = app.rack_;
  rack.Create();
  rack.Start();
  app.Run(fausty::Window::RunParams("Fausty Bubble"));
  rack.Stop();

  return 0;
}
