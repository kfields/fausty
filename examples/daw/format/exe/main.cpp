#include <fausty/rack/format/exe/exe_rack.h>
#include <fausty/rack/module/module.h>
#include <fausty/rack/module/faust_dsp.h>
#include <fausty/rack/module/faust_dsp_ui.h>

#include <fausty/app/app.h>

#include <fausty/widget/widget.h>
#include <fausty/widget/widget_manufacturer.h>
#include <fausty/view/rack_view.h>

#include "osc_dsp.h"
#include "freeverb_dsp.h"
#include "flanger_dsp.h"
#include "phaser_dsp.h"

using namespace fausty;

class OscDspImpl : public OscDsp
{
  REFLECT_ENABLE(FaustDsp)
};

class FreeVerbDspImpl : public FreeVerbDsp
{
  REFLECT_ENABLE(FaustDsp)
};

class FlangerDspImpl : public FlangerDsp
{
  REFLECT_ENABLE(FaustDsp)
};

class PhaserDspImpl : public PhaserDsp
{
  REFLECT_ENABLE(FaustDsp)
};

class MyApp : public App
{
public:
  MyApp()
  {
    OscDsp &m = ModelFactoryT<OscDspImpl>::Make(rack_);
    rack_.AddChild(m);

    FreeVerbDsp &m2 = ModelFactoryT<FreeVerbDspImpl>::Make(rack_);
    rack_.AddChild(m2);

    FlangerDsp &m3 = ModelFactoryT<FlangerDspImpl>::Make(rack_);
    rack_.AddChild(m3);

    PhaserDsp &m4 = ModelFactoryT<PhaserDspImpl>::Make(rack_);
    rack_.AddChild(m4);

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
