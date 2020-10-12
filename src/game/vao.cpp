#include "vao.h"

void vao::bind() const
{
    glBindVertexArray(id_);
}

void vao::unbind() const
{
    glBindVertexArray(0);
}

vao::~vao()
{
    glDeleteVertexArrays(1, &id_);
    for (auto vbo : vbos_)
    {
        vbo.remove();
    }
}
