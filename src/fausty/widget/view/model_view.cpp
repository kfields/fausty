#include "imgui.h"
#include "imnodes.h"

#include "../widget_builder.h"

#include "model_view.h"

void ModelView::Build() {
  WidgetBuilder builder;
  root_ = builder.Build(model());
}
