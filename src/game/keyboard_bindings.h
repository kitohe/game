#pragma once

#include <vector>

class keyboard_bindings
{

public:
    virtual std::vector<int> get_key_bindings() = 0;
};

