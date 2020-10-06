#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_constants.h"
#include "application_event.h"


class window
{
    GLFWwindow* window_{};

    void init();

    void create_window();

    void close();

public:
    window();

    virtual ~window();

    GLFWwindow* get_window() const;

    void enable_vsync(bool enable);
};
