#include "camera.h"

camera::camera()
{
   model_ = glm::mat4(1.0f);
    view_ = glm::lookAt(glm::vec3(2.5f, 2.5f, 2.5f),
                     glm::vec3(0.0f, 0.0f, 0.0f),
                        glm::vec3(0.0f, 0.0f, 1.0f));
    perspective_ = glm::perspective(glm::radians(45.0f), 
                                        game_constants::game_window_aspect_ratio,
                                        1.0f, 10.0f);
}

void camera::init(shader_loader shader_loader)
{
    shader_loader_ = shader_loader;
    shader_loader_.set_matrix4("model", model_);
    shader_loader_.set_matrix4("view", view_);
    shader_loader_.set_matrix4("perspective", perspective_);
}
