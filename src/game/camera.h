#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <functional>

#include "game_constants.h"
#include "shader_loader.h"
#include "window.h"


class camera
{
    glm::vec3 current_pos_;
    glm::vec3 center_;
    glm::vec3 up_;

    glm::mat4 model_;
    glm::mat4 view_;
    glm::mat4 perspective_;

    float camera_speed = 5.f;


    window& window_;
    shader_loader& shader_loader_;

    void move_cam_forward();
    void move_cam_backward();
    void move_cam_left();
    void move_cam_right();

public:
    camera(window& window, shader_loader& shader_loader);

    void init(window& window, shader_loader shader_loader);

    void update(double cam_x, double cam_y);

    void update_shader() const;
};

