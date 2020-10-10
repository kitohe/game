#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <functional>

#include "game_constants.h"
#include "keyboard_binding.h"
#include "shader_loader.h"
#include "window.h"
#include "time.h"


class camera
{
    glm::vec3 current_pos_;
    glm::vec3 center_;
    glm::vec3 up_;
    
    glm::mat4 model_;
    glm::mat4 view_;
    glm::mat4 perspective_;

    const float camera_speed = 2.5f;
    const float camera_sens = 0.1f;

    double last_cursor_pos_x = static_cast<double>(game_constants::game_window_width) / 2;
    double last_cursor_pos_y = static_cast<double>(game_constants::game_window_height) / 2;

    float yaw = -90.0f;
    float pitch = 0.0f;

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
