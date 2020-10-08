#include "window.h"

window::window()
{
    init();
}

window::~window()
{
    close();
}

void window::init()
{
    if (!glfwInit())
        return;

    create_window();

    glfwMakeContextCurrent(window_);

    glfwSetErrorCallback(application_event::error_callback);
    glfwSetWindowCloseCallback(window_, application_event::window_closing_callback);
    glfwSetKeyCallback(window_, application_event::key_callback);
    glfwSetCursorPosCallback(window_, application_event::mouse_pos_callback);

    glfwSetWindowUserPointer(window_, this);

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

GLFWwindow* window::get_window() const
{
    return window_;
}

void window::enable_vsync(bool enable)
{
   enable ? glfwSwapInterval(1) : glfwSwapInterval(0);
}

void window::on_key_press(int key)
{
    auto binds = key_binds_.get_key_binds();

    for (const auto& func: binds[key])
    {
        func();
    }
}
