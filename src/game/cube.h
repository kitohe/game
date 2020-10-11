#pragma once

#include "shader_loader.h"
#include "vbo.h"

class cube
{
     std::unique_ptr<vbo> cube_vbo;
public:

    void gen(shader_loader shader_loader);
    void draw();
};

