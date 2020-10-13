#include "uniform_float.h"

void uniform_float::load_matrix(GLfloat value) const
{
    glUniform1f(get_location(), value);
}
