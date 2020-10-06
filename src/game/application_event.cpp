#include "application_event.h"

void application_event::window_closing_callback(GLFWwindow* window)
{
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void application_event::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    application_event& app_event = *(application_event*)glfwGetWindowUserPointer(window);

    switch (action)
    {
        case GLFW_PRESS:
        {
            app_event.keyboard_.set_last_pressed_key(key);
            break;
        }
        case GLFW_RELEASE:
        {
            app_event.keyboard_.set_last_released_key(key);
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
