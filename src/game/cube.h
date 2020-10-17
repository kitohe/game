#pragma once

#include <vector>

#include "shader_loader.h"
#include "vbo.h"
#include "attribute.h"


class cube
{
     std::unique_ptr<vbo> cube_vbo;
public:

    void gen(shader_loader shader_loader);
    void draw();
};

