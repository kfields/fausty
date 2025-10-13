#pragma once

namespace fausty {

class Model;
class Widget;

class WidgetBuilder {
public:
  virtual Widget* Build(Model& model);
};

} // namespace fausty