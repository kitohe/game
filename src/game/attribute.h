#pragma once

#include <glad/glad.h>


class attribute
{
    GLuint id_;
    GLint size_;
    GLenum type_;
    GLsizei stride_;
    int offset_;
    GLboolean normalized_;
<<<<<<< HEAD
    GLsizei stride_;
    int offset_;

public:

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset);

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset, GLboolean normalized);
=======
    
public:

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset)
        : id_(id), size_(size), type_(type), stride_(stride), offset_(offset), normalized_(GL_FALSE) {  }

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset, GLboolean normalized)
        : id_(id), size_(size), type_(type), stride_(stride), offset_(offset), normalized_(normalized) {  }
>>>>>>> doing-vaos-properly

    void enable() const;
    void disable() const;
    void link() const;

    [[nodiscard]] GLsizei get_stride() const { return stride_; }
    [[nodiscard]] int get_offset() const { return offset_; }

private:

    [[nodiscard]] int get_size() const;
};
