#include "vbo.h"


vbo::vbo(GLenum type, GLenum usage): type_(type), usage_(usage)
{
    glGenBuffers(1, &id_);
}

void vbo::bind() const
{
    glBindBuffer(type_, id_);
}

void vbo::unbind() const
{
    glBindBuffer(type_, 0);
}

void vbo::remove() const
{
    glDeleteBuffers(1, &id_);
}

void vbo::alloc_and_store(GLsizeiptr size, const void* data) const
{
    glBufferData(type_, size, data, usage_);
}

void vbo::store(GLsizeiptr size, GLintptr offset, const void* data) const
{
    glBufferSubData(type_, offset, size, data);
}

vbo::~vbo()
{
    glDeleteBuffers(1, &id_);
}
