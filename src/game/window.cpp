#include "window.h"

void window::init()
{
    if (!glfwInit())
        return;

    create_window();

    glfwSetErrorCallback(application_event::error_callback);
    glfwSetWindowCloseCallback(window_, application_event::window_closing_callback);
    glfwSetKeyCallback(window_, application_event::key_callback);
    enable_vsync(true);
    gladLoadGL();
}

void window::create_window()
{
    window_ = glfwCreateWindow(game_constants::game_window_width, game_constants::game_window_height,
        "GAME", nullptr, nullptr);
}

void window::close()
{
    if (window_ == nullptr)
        return;

    glfwDestroyWindow(window_);
    glfwTerminate();
}

window::window()
{
    init();
}

window::~window()
{
    close();
}

GLFWwindow* window::get_window() const
{
    return window_;
}

void window::enable_vsync(bool enable)
{
   enable ? glfwSwapInterval(1) : glfwSwapInterval(0);
}
