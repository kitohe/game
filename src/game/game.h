#pragma once

#include <memory>

#include "game_constants.h"
#include "master_renderer.h"
#include "shader_loader.h"
#include "texture.h"
#include "cube.h"
#include "time.h"

#include "perlin_noise.h"


class game
{
    std::unique_ptr<master_renderer> master_renderer_;
    std::unique_ptr<camera> camera_;
    std::unique_ptr<perlin_noise> noise_;
    shader_loader shader_loader_;
    texture texture_;

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
