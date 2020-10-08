#pragma once

#include <functional>
#include <unordered_map>


class keyboard_binding
{
    static std::unordered_map<int, std::vector<std::function<void()>>> bindings_;

public:
    void add_key_bind(int key, std::function<void()> callback);
    std::unordered_map<int, std::vector<std::function<void()>>> get_key_binds();
};
