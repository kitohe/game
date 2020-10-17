#pragma once

#include <glad/glad.h>
#include <cstdint>


class attribute
{
    GLuint id_;
    GLint size_;
    GLenum type_;
    GLsizei stride_;
    int offset_;
    GLboolean normalized_;
    
public:

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset)
        : id_(id), size_(size), type_(type), stride_(stride), offset_(offset), normalized_(GL_FALSE) {  }

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset, GLboolean normalized)
        : id_(id), size_(size), type_(type), stride_(stride), offset_(offset), normalized_(normalized) {  }

    void enable() const;
    void disable() const;
    void link() const;

private:

    [[nodiscard]] int get_size() const;
};
