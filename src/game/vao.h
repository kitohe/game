#pragma once

#include <vector>

#include "vbo.h"


class vao
{
    int id_;
    std::vector<vbo> vbos_;

public:
    vao() {  }

    void bind() const;
    void unbind() const;
};

