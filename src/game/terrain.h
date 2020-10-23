#pragma once

#include "terrain_renderer.h"
#include "vao.h"
#include "camera.h"


class terrain_renderer;

class terrain
{
    vao& vao_;
    terrain_renderer& renderer_;
    unsigned long long vertex_count_;

public:

    terrain(vao& vao, terrain_renderer& renderer, uint32_t vertex_count) : vao_(vao), renderer_(renderer), vertex_count_(vertex_count) 
    { }

    void render() const;

    [[nodiscard]] vao& get_vao() const { return vao_; }
    [[nodiscard]] unsigned long long get_vertex_count() const { return vertex_count_; }
};

