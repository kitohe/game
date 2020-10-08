#include "keyboard_binding.h"

std::unordered_map<int, std::vector<std::function<void()>>> keyboard_binding::bindings_;

void keyboard_binding::add_key_bind(int key, std::function<void()> callback)
{
    bindings_[key].push_back(callback);
}

std::unordered_map<int, std::vector<std::function<void()>>> keyboard_binding::get_key_binds()
{
    return bindings_;
}
