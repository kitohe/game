#pragma once

#include <memory>

#include "game_constants.h"
#include "window.h"
#include "shader_loader.h"
#include "camera.h"
#include "texture.h"
#include "cube.h"
#include "time.h"

#include "perlin_noise.h"


class game
{
    window window_;
    shader_loader shader_loader_;
    std::unique_ptr<camera> camera_;
    texture texture_;

    std::unique_ptr<perlin_noise> noise_;

    int window_width_ = game_constants::game_window_width;
    int window_height_ = game_constants::game_window_height;

    double cam_x = 0;
    double cam_y = 0;

    void game_loop();

    void draw_fps(int fps) const;

    void init_shaders();

    void init_texture();
  
public:
    game();

    void run_game();
};
