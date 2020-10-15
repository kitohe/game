#pragma once

#include <glad/glad.h>


class attribute
{
    GLuint id_;
    GLint size_;
    GLenum type_;
    GLboolean normalized_;
    GLsizei stride_;
    int offset_;

public:

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset);

    attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset, GLboolean normalized);

    void enable() const;
    void disable() const;
    void set_pointer(int offset, int stride) const;

    [[nodiscard]] GLsizei get_stride() const { return stride_; }
    [[nodiscard]] int get_offset() const { return offset_; }

private:

    [[nodiscard]] int get_size() const;
};
