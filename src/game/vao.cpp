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
    
}
