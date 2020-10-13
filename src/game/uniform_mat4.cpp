#include "uniform_mat4.h"

void uniform_mat4::load_matrix(glm::mat4 matrix) const
{
    glUniformMatrix4fv(get_location(), 1, GL_FALSE, glm::value_ptr(matrix));
}
