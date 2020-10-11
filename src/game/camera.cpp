#include "camera.h"

void camera::move_cam_forward()
{
   current_pos_ += camera_speed * center_ * time::get_delta_time();
}

void camera::move_cam_backward()
{
    current_pos_ -= camera_speed * center_ * time::get_delta_time();
}

void camera::move_cam_left()
{
    current_pos_ -= glm::normalize(glm::cross(center_, up_)) * camera_speed * time::get_delta_time();
}

void camera::move_cam_right()
{
    current_pos_ += glm::normalize(glm::cross(center_, up_)) * camera_speed * time::get_delta_time();
}

camera::camera(shader_loader& shader_loader) : shader_loader_(shader_loader)
{
    add_key_binds();

    current_pos_ = glm::vec3(0.0f, 0.0f, 3.0f);
    center_      = glm::vec3(0.0f, 0.0f, -1.0f);
    up_          = glm::vec3(0.0f, 1.0f, 0.0f);

    model_       = glm::mat4(1.0f);
    view_        = glm::lookAt(current_pos_, current_pos_ + center_, up_);
    perspective_ = glm::perspective(glm::radians(45.0f), 
                                        game_constants::game_window_aspect_ratio,
                                        1.0f, 10.0f);
}

void camera::add_key_binds()
{
    key_binds_.add_key_bind(GLFW_KEY_W, std::function<void()>([this] {move_cam_forward();}));
    key_binds_.add_key_bind(GLFW_KEY_S, std::function<void()>([this] {move_cam_backward();}));
    key_binds_.add_key_bind(GLFW_KEY_A, std::function<void()>([this] {move_cam_left();}));
    key_binds_.add_key_bind(GLFW_KEY_D, std::function<void()>([this] {move_cam_right();}));
}

void camera::update(double cam_x, double cam_y)
{
    double x_offset = cam_x - last_cursor_pos_x;
    double y_offset = last_cursor_pos_y - cam_y;
    last_cursor_pos_x = cam_x;
    last_cursor_pos_y = cam_y;

    x_offset *= camera_sens;
    y_offset *= camera_sens;

    yaw += static_cast<float>(x_offset);
    pitch += static_cast<float>(y_offset);

    pitch = glm::clamp(pitch, -89.9f, 89.9f);

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    center_ = glm::normalize(direction);
    
    view_ = glm::lookAt(current_pos_, current_pos_ + center_, up_);
    update_shader();
}

void camera::update_shader() const
{
    shader_loader_.set_matrix4("model", model_);
    shader_loader_.set_matrix4("view", view_);
    shader_loader_.set_matrix4("perspective", perspective_);
}

void camera::init_camera(shader_loader& shader_loader)
{
    shader_loader_ = shader_loader;
}
