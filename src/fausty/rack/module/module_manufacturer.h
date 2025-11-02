#pragma once

#include <map>
#include <string>
#include <typeindex>
#include <vector>

namespace fausty {

class ModelFactory;

class ModuleManufacturer {
public:
    static ModuleManufacturer &instance() noexcept {
        static ModuleManufacturer *self = new ModuleManufacturer();
        return *self;
    }
    void AddFactory(ModelFactory &factory);
    ModelFactory *GetFactory(std::type_index &key);
    ModelFactory *FindFactory(const std::type_index &type);
    // Data members
    std::vector<ModelFactory *> factories_;
    std::map<std::type_index, ModelFactory *> factory_map_;
};

#define REGISTER_MODULE_FACTORY(T)                                             \
    extern ModelFactory *Get##T##Factory();                                   \
    ModuleManufacturer::instance().AddFactory(*Get##T##Factory());

} // namespace fausty