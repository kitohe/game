#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <functional>

#include "game_constants.h"
#include "keyboard_binding.h"
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

    shader_loader& shader_loader_;
    keyboard_binding key_binds_;

    void add_key_binds();

    void move_cam_forward();
    void move_cam_backward();
    void move_cam_left();
    void move_cam_right();
    
public:
    camera(shader_loader& shader_loader);

    void init_camera(shader_loader& shader_loader);

    void update(double cam_x, double cam_y);

    void update_shader() const;
};
