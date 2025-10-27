#include <fausty/rack/format/exe/exe_rack.h>
#include <fausty/rack/module/module.h>
#include <fausty/rack/module/faust_dsp.h>
#include <fausty/rack/module/faust_dsp_ui.h>

#include <fausty/app/app.h>

#include <fausty/view/rack_view.h>
#include <fausty/widget/widget.h>
#include <fausty/widget/widget_manager.h>

#include "chain_dsp.h"

using namespace fausty;

class ChainDspImpl : public ChainDsp
{
  REFLECT_ENABLE(FaustDsp)
};

class MyApp : public App
{
public:
  MyApp()
  {
    ChainDsp &m = ModelFactoryT<ChainDspImpl>::Make(rack_);
    rack_.AddChild(m);
    view_ = new RackView(rack_);
  }

  void Draw() override
  {
    App::Draw();
    view_->Draw();
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
  app.Run();
  rack.Stop();
}
