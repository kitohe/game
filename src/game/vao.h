#pragma once

#include <iostream>
#include <vector>

#include "vbo.h"
#include "attribute.h"


class vao
{
    GLuint id_;
    std::vector<std::shared_ptr<vbo>> vbos_;
    std::vector<attribute>& attributes_;

    void link_attributes();

public:
    explicit vao(std::vector<attribute>& attributes);

    void bind() const;
    void unbind() const;
    void create(GLenum usage, int data_size, const void* data);

    static void currently_bound_vao();

    ~vao();
};

