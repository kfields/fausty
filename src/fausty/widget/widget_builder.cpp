#include <fausty/rack/model.h>

#include "widget_manager.h"
#include "widget_builder.h"
#include "widget.h"

namespace fausty {

Widget* WidgetBuilder::Build(Model& model) {
  auto type = ::reflect::get_type(model);
  WidgetFactory& factory = *WidgetManager::GetFactory(type);
  Widget& widget = *factory.Produce(model);
  for (const auto child : model.children_) {
    widget.AddChild(Build(*child));
  }
  return &widget;
}

} // namespace fausty