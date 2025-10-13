#include "context.h"

class ImPlotContext : public Context {
public:
  void Create() override;
  void Destroy() override;
};
void ImPlotContext::Create() {
  ImPlot::CreateContext();
}
void ImPlotContext::Destroy() {
  ImPlot::DestroyContext();
}