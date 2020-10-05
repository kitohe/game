#pragma once

#include "game_constants.h"
#include "shader_loader.h"
#include "camera.h"
#include "texture.h"
#include "cube.h"

#include <GLFW/glfw3.h>

class game
{
    GLFWwindow *game_window_;
    shader_loader shader_loader_;
    camera camera_;
    texture texture_;

    int window_width_ = game_constants::game_window_width;
    int window_height_ = game_constants::game_window_height;

    double cam_x = 0;
    double cam_y = 0;

    void game_loop();

    void clean() const;

    void draw_fps(int fps) const;

    void key_callback(GLFWwindow *window);

    static void error_callback(int error, const char* description);

    bool init_opengl();

    void init_shaders();

    void init_camera();

    void init_texture();

    bool create_game_window();
  
public:

    game() : game_window_(nullptr) { }

    void run_game();
};
