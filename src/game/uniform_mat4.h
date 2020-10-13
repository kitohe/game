#pragma once
#include "uniform.h"


class uniform_mat4 : public uniform
{
    uniform_mat4(const GLchar* name): uniform(name) {  }

    void load_matrix(glm::mat4 matrix) const;
};

