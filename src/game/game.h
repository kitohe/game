#pragma once
#include <GLFW/glfw3.h>

#include "game_constants.h"


class game
{
    GLFWwindow *game_window_;

    int window_width_ = game_constants::game_window_width;
    int window_height_ = game_constants::game_window_height;
    
    void game_loop();

    void clean() const;

    void draw_fps(int fps) const;

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void error_callback(int error, const char* description);

    bool init_opengl();

    bool create_game_window();
  
public:

    game() : game_window_(nullptr) { }

    void run_game();
};
