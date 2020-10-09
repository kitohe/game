#pragma once

#include <iostream>

#include "window.h"


class application_event
{
public:
    static void window_closing_callback(GLFWwindow* window);
    static void key_callback(GLFWwindow* app_window, int key, int scancode, int action, int mods);
    static void mouse_pos_callback(GLFWwindow* app_window, double x, double y);
    static void error_callback(int error, const char* description);
};

