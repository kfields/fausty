#pragma once

#include <vector>

#include <fausty/part.h>

class Model :public Part {
public:
  Model() {}
  void AddChild(Model& model) {
    children_.push_back(&model);
  }
  //Accessors
  Model& parent() { return *(Model*)owner_; }
  //Data members
  std::vector<Model*> children_;
  //Pins
  REFLECT_ENABLE(Part)
};

template<typename T = Model>
class ModelT : T {
  void AddChild(T& model) {
    children_.push_back(&model);
  }
  //Data members
  std::vector<T*> children_;
};

//Factory
class ModelFactory {
public:
  virtual Model& Produce(Model& model) = 0;
  virtual std::type_index GetKey() = 0;
};

template<typename T>
class ModelFactoryT : public ModelFactory {
public:
  ModelFactoryT() {}
  static T& Make(Model& parent) {
    T& model = *new T();
    model.Create(parent);
    return model;
  }
  virtual Model& Produce(Model& parent) override {
    return Make(parent);
  }
  virtual std::type_index GetKey() override { return std::type_index(typeid(T)); }
  //Data members
};
