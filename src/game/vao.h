#pragma once

#include <vector>

#include "vao.h"
#include "vbo.h"
#include "attribute.h"


class vao
{
    GLuint id_;
    std::vector<vbo> vbos_;
    std::vector<attribute> attributes_;

public:
    vao()
    {
        glGenVertexArrays(1, &id_);
    }

    void bind() const;
    void unbind() const;
    void link_attributes(std::vector<attribute>& attributes);
    void init(const void* data, GLenum usage, std::vector<attribute>& attributes);

    ~vao();
};

