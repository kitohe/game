#include "uniform.h"

void uniform::store_uniform_location(int programId)
{
    location_ = glGetUniformLocation(programId, name_);
    if (location_ == -1)
        std::cerr << "Uniform variable named: " << name_ << " couldn't be found for shader program with id: "
                  << programId << std::endl;
}

int uniform::get_location() const
{
    return location_;
}
