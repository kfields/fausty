#pragma once

#include <vector>
#include <typeindex>

class Model;
class Widget;

class WidgetContainer {
public:
  virtual ~WidgetContainer() = default;
  void AddWidget(Widget* widget) { widgets_.push_back(widget); }
  //Data members
  std::vector<Widget*> widgets_;
};

class Widget : public WidgetContainer {
public:
  virtual void Draw() { DrawChildren(); }
  void DrawChildren() { for(auto child : widgets_) DrawChild(*child); }
  virtual void DrawChild(Widget& child) { child.Draw(); }
  //Data members
};

template<typename T>
class WidgetT : public Widget {
public:
  WidgetT(T& model) : model_(&model) {}
  //Data members
  T* model_;
};

//Factory
class WidgetFactory {
public:
  virtual Widget* Produce(Model& model) = 0;
  virtual std::type_index GetKey() = 0;
};

template<typename T, typename N = Model>
class WidgetFactoryT : public WidgetFactory {
  virtual Widget* Produce(Model& model) override {
    return new T((N&)model);
  }
  virtual std::type_index GetKey() override { return std::type_index(typeid(N)); }
  //Data members
};

#define DECLARE_WIDGET(T, N)
#define DEFINE_WIDGET(T, N) \
  WidgetFactoryT<T, N> T##Factory; \
  WidgetFactory* Get##T##Factory() { return &T##Factory; }
