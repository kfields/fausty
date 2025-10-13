//#include <rttr/type>
#include "../reflect.h"
#include "widget_manager.h"
#include "widget.h"

namespace fausty {

std::vector<WidgetFactory*> WidgetManager::factories_;
std::map<std::type_index, WidgetFactory*> WidgetManager::factory_map_;

void WidgetManager::AddFactory(WidgetFactory& factory) {
  factories_.push_back(&factory);
  factory_map_[factory.GetKey()] = &factory;
}

WidgetFactory* WidgetManager::GetFactory(std::type_index& key) {
  return FindFactory(key);
}

WidgetFactory* WidgetManager::FindFactory(const std::type_index& t) {
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