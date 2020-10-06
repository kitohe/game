#include "application_event.h"

void application_event::window_closing_callback(GLFWwindow* window)
{
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void application_event::key_callback(GLFWwindow* app_window, int key, int scancode, int action, int mods)
{
    window& win = *(window*)glfwGetWindowUserPointer(app_window);

    switch (action)
    {
        case GLFW_PRESS:
        {
            win.on_key_press(key);
            break;
        }
        default:
        {
            break;
        }
    }
}

void application_event::error_callback(int error, const char* description)
{
    std::cerr << error <<  " Error: " << description << std::endl; 
}
