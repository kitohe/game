#include "attribute.h"

#include <cstdint>

attribute::attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset): id_(id), size_(size), type_(type),
                                                                                      normalized_(false),
                                                                                      stride_(stride),
                                                                                      offset_(offset)
{
}

attribute::attribute(GLuint id, GLint size, GLenum type, GLsizei stride, int offset, GLboolean normalized): id_(id),
    size_(size), type_(type),
    normalized_(normalized),
    stride_(stride), offset_(offset)
{
}

void attribute::enable() const
{
    glEnableVertexAttribArray(id_);
}

void attribute::disable() const
{
    glDisableVertexAttribArray(id_);
}

void attribute::link() const
{
    const int ptr = get_size() * offset_;
    glVertexAttribPointer(id_, size_, type_, normalized_, stride_, reinterpret_cast<void*>(static_cast<intptr_t>(ptr)));
}

int attribute::get_size() const
{
    if (type_ == GL_FLOAT || type_ == GL_INT || type_ == GL_UNSIGNED_INT ||
        type_ == GL_UNSIGNED_INT_2_10_10_10_REV)
        return 4;
    if (type_ == GL_SHORT || type_ == GL_UNSIGNED_SHORT)
        return 2;
    if (type_ == GL_BYTE || type_ == GL_UNSIGNED_BYTE)
        return 1;

    return 0;
}
