#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "game_constants.h"
#include "shader_loader.h"

class camera
{
    glm::mat4 model_;
    glm::mat4 view_;
    glm::mat4 perspective_;
    
    shader_loader shader_loader_;

public:
    camera();

    void init(shader_loader shader_loader);
};

