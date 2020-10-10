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

    void close() const;

    double cursor_pos_x;
    double cursor_pos_y;

public:

    window();

    virtual ~window();

    GLFWwindow* get_window() const;

    void enable_vsync(bool enable);

    void on_key_press(int key);

    void set_cursor_pos(double x, double y);

    double get_mouse_x_pos() const { return cursor_pos_x; }

    double get_mouse_y_pos() const { return cursor_pos_y; }
};
