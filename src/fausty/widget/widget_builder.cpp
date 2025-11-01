#include <fausty/rack/model.h>

#include "widget_manufacturer.h"
#include "widget_builder.h"
#include "widget.h"

namespace fausty {

Widget* WidgetBuilder::Build(Model& model) {
  auto type = ::reflect::get_type(model);

  auto manufacturer = WidgetManufacturer::instance();

  WidgetFactory& factory = *manufacturer.GetFactory(type);
  Widget& widget = *factory.Produce(model);
  for (const auto child : model.children_) {
    widget.AddChild(Build(*child));
  }
  return &widget;
}

} // namespace fausty