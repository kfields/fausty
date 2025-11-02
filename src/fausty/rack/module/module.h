#pragma once

#include <vector>

#include <fausty/rack/node.h>
#include <fausty/rack/audio_pin.h>

namespace fausty {

class Module : public Node
{
public:
  //
  virtual bool Create(Part &owner) override;
  virtual Audio ProcessAudio(Audio input = Audio()) { return Audio(); }
  virtual void Process() {}
  // Data members
  const char *label_ = nullptr;
  AudioPin *audio_in_ = nullptr;
  AudioPin *audio_out_ = nullptr;

  REFLECT_ENABLE(Node)
};

// Factory
/*
class ModuleFactory {
public:
    virtual Module *Produce(Model &model) = 0;
    virtual std::type_index GetKey() = 0;
};

template <typename T, typename N = Model>
class ModuleFactoryT : public ModuleFactory {
    Module *Produce(Model &model) override { return new T((N &)model); }
    std::type_index GetKey() override {
        return std::type_index(typeid(N));
    }
    // Data members
};

*/

/*
template <typename T> class ModelFactoryT : public ModelFactory {
public:
    ModelFactoryT() {}
    static T &Make(Model &parent) {
        T &model = *new T();
        model.Create(parent);
        return model;
    }
    virtual Model &Produce(Model &parent) override { return Make(parent); }
    virtual std::type_index GetKey() override {
        return std::type_index(typeid(T));
    }
    // Data members
};
*/

template <typename T>
class ModuleFactoryT : public ModelFactoryT<T> {
public:
    ModuleFactoryT(std::string name, std::string category) : name_(name), category_(category) {}
    // Data members
    std::string name_;
    std::string category_;
};

#define DEFINE_MODULE_FACTORY(T, NAME, CATEGORY)                                                    \
    ModuleFactoryT<T> T##Factory(NAME, CATEGORY);                                           \
    ModuleFactory *Get##T##Factory() { return &T##Factory; }

} // namespace fausty