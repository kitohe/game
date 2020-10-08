#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_constants.h"
#include "keyboard_event.h"
#include "application_event.h"
#include "keyboard_binding.h"


class window
{
    GLFWwindow* window_;

    keyboard_binding key_binds_;

    void init();

    void create_window();

    void close();

public:

    window();

    virtual ~window();

    GLFWwindow* get_window() const;

    void enable_vsync(bool enable);

    void on_key_press(int key);
};
