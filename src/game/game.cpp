#include "game.h"


void game::game_loop()
{
    int frame_counter = 0;
    double start_time = glfwGetTime();

    cube cube;
    cube.gen(*shader_loader_);

    auto* window = window_.get_window();

    while (!glfwWindowShouldClose(window_.get_window()))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, window_width_, window_height_);
        glfwGetFramebufferSize(window, &window_width_, &window_height_);
        
        
        camera_->update(cam_x / game_constants::game_window_width, cam_y / game_constants::game_window_height);
        glfwPollEvents();

        cube.draw();              
        glfwSwapBuffers(window);
       

        if (glfwGetTime() - start_time >= 1.0)
        {
            draw_fps(frame_counter);
            start_time += 1.0;
            frame_counter = 0;
        }
        frame_counter++;
        
    }
}

void game::init_shaders()
{
    shader_loader_->create_shader_program(game_constants::cube_vertex_shader_path,
        game_constants::cube_fragment_shader_path);

    shader_loader_->use_program();
}

void game::init_camera()
{
    camera_->init(window_, *shader_loader_);
}

void game::init_texture()
{
    texture_.load(R"(C:\Users\dmadr\Documents\Projects\CPP\game\assets\textures\marble\marble.jpg)");
    texture_.generate_texture();
    texture_.set_active(0);
}

void game::draw_fps(const int fps) const
{
    std::cout << "FPS: " << fps << std::endl;
}

void game::run_game()
{
    init_shaders();
    init_camera();
    init_texture();

    game_loop();
}
