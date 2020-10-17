#pragma once

#include <vector>

#include "shader_loader.h"
#include "vao.h"
#include "attribute.h"


class cube
{
    std::unique_ptr<vao> cube_vao;

public:

    void gen(shader_loader shader_loader);
    void draw();
};

