#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <unordered_map>
#include <functional>

#include "game_constants.h"
#include "keyboard_event.h"
#include "application_event.h"


class window
{
    GLFWwindow* window_;

    void init();

    void create_window();

    void close();

    std::unordered_map<int, std::vector<std::function<void()>>> bindings_;

public:

    window();

    virtual ~window();

    GLFWwindow* get_window() const;

    void enable_vsync(bool enable);

    void add_key_binding(int key, const std::function<void()> callback);

    void on_key_press(int key);
};
