#include "imgui.h"

#include "widget.h"
#include <fausty/rack/control/num_entry.h>

namespace fausty {

class NumEntryWidget : public WidgetT<NumEntry> {
public:
  NumEntryWidget(NumEntry& model) : WidgetT<NumEntry>(model) {}
  void Draw() override {
    ImGui::InputFloat(model_->label_, model_->zone_);
  }
  DECLARE_WIDGET(NumEntryWidget, NumEntry)
};
DEFINE_WIDGET(NumEntryWidget, NumEntry)

} // namespace fausty