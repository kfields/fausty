#pragma once

class Model;
class Widget;

class WidgetBuilder {
public:
  virtual Widget* Build(Model& model);
};