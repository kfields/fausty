#include "implot.h"

#include "implot_context.h"


void ImPlotContext::Create() {
  ImPlot::CreateContext();
}
void ImPlotContext::Destroy() {
  ImPlot::DestroyContext();
}