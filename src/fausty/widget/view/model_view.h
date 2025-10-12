#pragma once

#include "view.h"

class Model;
class Widget;

class ModelView : public View {
public:
  virtual Model& model() = 0;
  void Build();
  //Data members
  Widget* root_ = nullptr;
};

template<typename T>
class ModelViewT : public ModelView {
public:
  ModelViewT(T& model) : model_(&model) {}
  virtual Model& model() override { return *model_; }
  //Data members
  T* model_;
};
