#include "attribute.h"

void attribute::enable() const
{
    glEnableVertexAttribArray(id_);
}

void attribute::disable() const
{
    glDisableVertexAttribArray(id_);
}

void attribute::set_pointer(int offset, int stride) const
{
    glVertexAttribPointer(id_, size_, type_, normalized_, stride, (void*)(offset * get_size()));
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
