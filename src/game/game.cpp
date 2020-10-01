#include <glad/glad.h>
#include <iostream>

#include "game.h"
#include "cube.h"


void game::game_loop()
{
    int frame_counter = 0;
    double start_time = glfwGetTime();

    cube cube;
    cube.gen();

    while (!glfwWindowShouldClose(game_window_))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, window_width_, window_height_);
        glfwGetFramebufferSize(game_window_, &window_width_, &window_height_);
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
    glfwSetKeyCallback(game_window_, key_callback);
    glfwSetErrorCallback(error_callback);
    glfwSwapInterval(1); // enables vsync
    gladLoadGL();

    glEnable(GL_DEPTH_TEST);

    return true;
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

void game::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
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

    game_loop();
        
}
