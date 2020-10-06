#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

#include "keyboard_event.h"


class application_event
{
    keyboard_event keyboard_;

public:
    static void window_closing_callback(GLFWwindow* window);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void error_callback(int error, const char* description);
};

