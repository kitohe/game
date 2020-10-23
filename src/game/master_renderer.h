#pragma once

#include <memory>

#include "window.h"
#include "camera.h"
#include "terrain.h"


class master_renderer
{
    window window_;

    void prepare() const;

public:

    master_renderer(bool vsync) { window_.enable_vsync(vsync); }

    void render(terrain& terrain, camera& cam) const;

    [[nodiscard]] GLFWwindow* get_window() const { return window_.get_window(); }
};
