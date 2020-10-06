#pragma once

#include <iostream>

#include "window.h"


class application_event
{
public:
    static void window_closing_callback(GLFWwindow* window);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void error_callback(int error, const char* description);
};

