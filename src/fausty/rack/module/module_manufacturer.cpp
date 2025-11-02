//#include <rttr/type>
#include "../reflect.h"
#include "module_manufacturer.h"
#include "module.h"

namespace fausty {

void ModuleManufacturer::AddFactory(ModelFactory& factory) {
  factories_.push_back(&factory);
  factory_map_[factory.GetKey()] = &factory;
}

ModelFactory* ModuleManufacturer::GetFactory(std::type_index& key) {
  return FindFactory(key);
}

ModelFactory* ModuleManufacturer::FindFactory(const std::type_index& t) {
  // exact match
  if (auto it = factory_map_.find(t); it != factory_map_.end())
    return it->second;

  // search bases (depth-first)
  for (const auto& b : ::reflect::Registry::instance().bases_of(t)) {
    if (auto* f = FindFactory(b))
      return f;
  }
  return nullptr;
}

} // namespace fausty