//#include "imgui.h"
#include "implot.h"

#include "widget.h"
#include <fausty/rack/control/h_bargraph.h>

namespace fausty {

class HBarGraphWidget : public WidgetT<HBarGraph> {
public:
  HBarGraphWidget(HBarGraph& model) : WidgetT<HBarGraph>(model) {}
  void Draw() override {
    //ImGui::PlotHistogram(model_->label_, model_->zone_, 1, 0, NULL, model_->min_, model_->max_, ImVec2(0, 80.0f));
    ImPlot::BeginPlot(model_->label_);
    ImPlot::PlotBars<fy_real>(model_->label_, model_->zone_, 1, 0.67, 0, ImPlotBarsFlags_Horizontal);
    ImPlot::EndPlot();
  }
  DECLARE_WIDGET(HBarGraphWidget, HBarGraph)
};
DEFINE_WIDGET(HBarGraphWidget, HBarGraph)

} // namespace fausty