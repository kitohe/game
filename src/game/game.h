#pragma once
#include <GLFW/glfw3.h>

class game
{
    GLFWwindow *game_window_;

    int window_width_ = 1280;
    int window_height_ = 720;
    
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
