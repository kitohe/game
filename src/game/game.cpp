#include "game.h"


void game::game_loop()
{
    int frame_counter = 0;
    double start_time = glfwGetTime();

    cube cube;
    cube.gen(shader_loader_);

    while (!glfwWindowShouldClose(game_window_))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, window_width_, window_height_);
        glfwGetFramebufferSize(game_window_, &window_width_, &window_height_);
        
        key_callback(game_window_);
        camera_.update(cam_x / game_constants::game_window_width, cam_y / game_constants::game_window_height);
        glfwPollEvents();

        cube.draw();              
        glfwSwapBuffers(game_window_);
       

        if (glfwGetTime() - start_time >= 1.0)
        {
            draw_fps(frame_counter);
            start_time += 1.0;
            frame_counter = 0;
        }
        frame_counter++;
        
    }

    clean();
}

void game::clean() const
{
    if (game_window_ == nullptr)
        return;
    
    glfwDestroyWindow(game_window_);
    glfwTerminate();
}

bool game::init_opengl()
{
    if (!glfwInit())
        return false;

    if (!create_game_window())
        return false;
    
    glfwMakeContextCurrent(game_window_);
    glfwSetErrorCallback(error_callback);
    glfwSwapInterval(1); // enables vsync
    gladLoadGL();

    glEnable(GL_DEPTH_TEST);

    return true;
}

void game::init_shaders()
{
    shader_loader_.create_shader_program(game_constants::cube_vertex_shader_path,
        game_constants::cube_fragment_shader_path);

    shader_loader_.use_program();
}

void game::init_camera()
{
    camera_.init(shader_loader_);
}

void game::init_texture()
{
    texture_.load(R"(C:\Users\dmadr\Documents\Projects\CPP\game\assets\textures\marble\marble.jpg)");
    texture_.generate_texture();
    texture_.set_active(0);
}

bool game::create_game_window()
{
    game_window_ = glfwCreateWindow(window_width_, window_height_, "GAME", nullptr, nullptr);

    return game_window_;
}

void game::draw_fps(const int fps) const
{
    std::cout << "FPS: " << fps << std::endl;
}

void game::key_callback(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    glfwGetCursorPos(window, &cam_x, &cam_y);
    std::cout << "X: " << cam_x / game_constants::game_window_width << " Y: " << cam_y / game_constants::game_window_height << std::endl;

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        std::cout << "UP\n";
    }

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        std::cout << "DOWN\n";
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        std::cout << "LEFT\n";   
    }

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        std::cout << "RIGHT\n";
    }
}

void game::error_callback(int error, const char* description)
{
    std::cout << "Error: " << description << std::endl;
}

void game::run_game()
{
    if(!init_opengl())
    {
        std::cerr << "Error while initializing OpenGL. Quitting!" << std::endl;
        return;
    }

    init_shaders();
    init_camera();
    init_texture();

    game_loop();
        
}
