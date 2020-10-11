#pragma once

#include <vector>

#include "vbo.h"


class vao
{
    GLuint id_;
    std::vector<vbo> vbos_;

public:
    vao()
    {
        glGenVertexArrays(1, &id_);
    }

    void bind() const;
    void unbind() const;

    ~vao();
};

