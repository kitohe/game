#include "uniform_int.h"

void uniform_int::load_int(GLint value) const
{
    glUniform1i(get_location(), value);
}
