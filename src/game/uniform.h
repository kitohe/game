#pragma once

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class uniform
{
    const GLchar* name_;
    int location_;

protected:

    explicit uniform(const GLchar* name) : name_(name) {  }
    void store_uniform_location(int programId);
    [[nodiscard]] int get_location() const;
};

