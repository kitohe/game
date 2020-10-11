#pragma once

#include <glad/glad.h>

class vbo
{
    GLuint id_;
    GLenum type_;
    GLenum usage_;

public:

    vbo(GLenum type, GLenum usage);
    void bind() const;
    void unbind() const;
    void remove() const;
    void alloc_and_store(GLsizeiptr size, const void* data) const;
    void store(GLsizeiptr size, GLintptr offset, const void* data) const;
    ~vbo();
};

