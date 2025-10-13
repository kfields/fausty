#include <fausty/rack/format/exe/exe_rack.h>
#include <fausty/rack/module/module.h>
#include <fausty/rack/module/faust_dsp.h>
#include <fausty/rack/module/faust_dsp_ui.h>

#include <fausty/app/app.h>

#include <fausty/widget/widget.h>
#include <fausty/widget/widget_manager.h>
#include <fausty/view/rack_view.h>

#include "frenchbell_dsp.h"

class FrenchBellDspImpl : public FrenchBellDsp
{
public:
  REFLECT_ENABLE(FrenchBellDsp)
};

class MyApp : public App
{
public:
  MyApp()
  {
    FrenchBellDsp &m = ModelFactoryT<FrenchBellDspImpl>::Make(rack_);
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
  app.Run();
  rack.Stop();

  return 0;
}
