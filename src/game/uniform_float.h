#pragma once
#include "uniform.h"


class uniform_float : public uniform
{
public:
    uniform_float(const GLchar* name) : uniform(name) {  }

    void load_matrix(GLfloat value) const;
};
