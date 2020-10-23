#include "game.h"


void game::game_loop()
{
    int frame_counter = 0;
    double start_time = glfwGetTime();

    //cube cube;
    //cube.gen(shader_loader_);

    auto t = terrain_gen_->generate_terrain(10);

    auto* window = master_renderer_->get_window();
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        master_renderer_->render(*t,*camera_);
        glfwGetFramebufferSize(window, &window_width_, &window_height_);
        glfwPollEvents();

        //cube.draw();              
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

void game::init_texture()
{
    texture_.load(R"(C:\Users\dmadr\Documents\Projects\CPP\game\assets\textures\marble\marble.jpg)");
    texture_.generate_texture();
    texture_.set_active(0);
}

game::game()
{
    master_renderer_ = std::make_unique<master_renderer>(true);
    camera_ = std::make_unique<camera>(shader_loader_);
    noise_ = std::make_unique<perlin_noise>(3, 0.35f, 10.0f);
    terrain_gen_ = std::make_unique<split_terrain_generator>(*noise_);
}

void game::draw_fps(const int fps) const
{
    std::cout << "FPS: " << fps << std::endl;
}

void game::run_game()
{
    init_shaders();
    init_texture();

    game_loop();
}
