#include "camera.h"

void camera::move_cam_forward()
{
   current_pos_.x += 0.05f * camera_speed;
}

void camera::move_cam_backward()
{
    current_pos_.x -= 0.05f * camera_speed;
}

void camera::move_cam_left()
{
    current_pos_.z -= 0.05f * camera_speed;
}

void camera::move_cam_right()
{
    current_pos_.z += 0.05f * camera_speed;
}

camera::camera(window& window, shader_loader& shader_loader) : window_(window), shader_loader_(shader_loader)
{
    current_pos_ = glm::vec3(0.0f, 2.5f, 2.5f);
    center_ = glm::vec3(0.0f, 0.0f, 0.0f);
    up_ = glm::vec3(0.0f, 1.0f, 0.0f);

    model_ = glm::mat4(1.0f);
    view_ = glm::lookAt(current_pos_, center_, up_);
    perspective_ = glm::perspective(glm::radians(45.0f), 
                                        game_constants::game_window_aspect_ratio,
                                        1.0f, 10.0f);
}

void camera::init(window& window, shader_loader shader_loader)
{
    shader_loader_ = shader_loader;
    window_ = window;

    window_.add_key_binding(GLFW_KEY_W, std::function<void()>([this] {move_cam_forward();}));
    window_.add_key_binding(GLFW_KEY_S, std::function<void()>([this] {move_cam_backward();}));
    window_.add_key_binding(GLFW_KEY_A, std::function<void()>([this] {move_cam_left();}));
    window_.add_key_binding(GLFW_KEY_D, std::function<void()>([this] {move_cam_right();}));
}

void camera::update(double cam_x, double cam_y)
{
    center_.x = (float)cam_x * camera_speed;
    center_.y = (float)cam_y * camera_speed;
    //center_.y+=0.01f;
    //std::cout << current_pos_.x << " ";
    view_ = glm::lookAt(current_pos_, center_, up_);
    update_shader();
}

void camera::update_shader() const
{
    shader_loader_.set_matrix4("model", model_);
    shader_loader_.set_matrix4("view", view_);
    shader_loader_.set_matrix4("perspective", perspective_);
}
