#include "game.h"


void game::game_loop()
{
    int frame_counter = 0;
    double start_time = glfwGetTime();

    cube cube;
    cube.gen(shader_loader_);

    auto* window = window_.get_window();
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window_.get_window()))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, window_width_, window_height_);
        glfwGetFramebufferSize(window, &window_width_, &window_height_);
        
        camera_->update(window_.get_mouse_x_pos(), window_.get_mouse_y_pos());
        glfwPollEvents();
        
        cube.draw();              
        glfwSwapBuffers(window);
       
        time::update_time(glfwGetTime());
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
    shader_loader_.create_shader_program(game_constants::cube_vertex_shader_path,
        game_constants::cube_fragment_shader_path);

    shader_loader_.use_program();
}

void game::init_camera()
{
    return;
}

void game::init_texture()
{
    texture_.load(R"(C:\Users\dmadr\Documents\Projects\CPP\game\assets\textures\marble\marble.jpg)");
    texture_.generate_texture();
    texture_.set_active(0);
}

game::game()
{
    camera_ = std::make_unique<camera>(shader_loader_);
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
