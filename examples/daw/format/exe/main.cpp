#include <fausty/rack/model_manufacturer.h>

#include <fausty/rack/format/exe/exe_rack.h>
#include <fausty/rack/module/faust_dsp.h>
#include <fausty/rack/module/faust_dsp_ui.h>
#include <fausty/rack/module/module.h>

#include <fausty/app/app.h>

#include <fausty/view/rack_view.h>
#include <fausty/widget/widget_manufacturer.h>

using namespace fausty;

class MyApp final : public App {
public:
    MyApp() {
        extern void InitFaustDspLibrary();
        InitFaustDspLibrary();
        // Create the rack view
        view_ = new RackView(rack_);
    }

    void Draw() override {
        App::Draw();
        view_->Draw();
    }
    // Data members
    ExeRack rack_;
    RackView *view_;
};

int main(int, char **) {
    MyApp &app = *new MyApp();
    ExeRack &rack = app.rack_;
    rack.Create();
    rack.Start();
    app.Run();
    rack.Stop();
}
