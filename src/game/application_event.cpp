#include "application_event.h"

void application_event::window_closing_callback(GLFWwindow* window)
{
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void application_event::key_callback(GLFWwindow* app_window, int key, int scancode, int action, int mods)
{
    window& win = *(window*)glfwGetWindowUserPointer(app_window);
    win.on_key_press(key);
}

void application_event::mouse_pos_callback(GLFWwindow* app_window, double x, double y)
{
    std::cout << "MOUSE AT: " << x << " " << y << std::endl;
    window& win = *(window*)glfwGetWindowUserPointer(app_window);
    win.set_cursor_pos(x, y);
}

void application_event::error_callback(int error, const char* description)
{
    std::cerr << error <<  " Error: " << description << std::endl; 
}
