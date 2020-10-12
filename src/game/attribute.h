#pragma once

#include <glad/glad.h>
#include <cstdint>


class attribute
{
    GLuint id_;
    GLint size_;
    GLenum type_;
    GLboolean normalized_;

public:

    attribute(GLuint id, GLint size, GLenum type)
        : id_(id), size_(size), type_(type), normalized_(GL_FALSE) {  }

    attribute(GLuint id, GLint size, GLenum type, GLboolean normalized)
        : id_(id), size_(size), type_(type), normalized_(normalized) {  }

    void enable() const;
    void disable() const;
    void set_pointer(int offset, int stride) const;

private:

    [[nodiscard]] int get_size() const;
};
