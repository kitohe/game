#pragma once

#include "shader_loader.h"
#include "uniform_int.h"
#include "attribute.h"
#include "vao.h"
#include "vbo.h"


class cube
{
     std::unique_ptr<vbo> cube_vbo;
public:

    void gen(shader_loader shader_loader);
    void draw();
};

