#pragma once
#include "uniform.h"


class uniform_int : public uniform
{
public:
    uniform_int(const GLchar* name) : uniform(name) {  }

    void load_int(GLint value) const;
};
