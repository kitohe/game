#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "game_constants.h"
#include "shader_loader.h"

class camera
{
    glm::vec3 current_pos_;
    glm::vec3 center_;
    glm::vec3 up_;

    glm::mat4 model_;
    glm::mat4 view_;
    glm::mat4 perspective_;

    float camera_speed = 5.f;

    shader_loader shader_loader_;

public:
    camera();

    void init(shader_loader shader_loader);

    void update(double cam_x, double cam_y);

    void update_shader() const;
};

