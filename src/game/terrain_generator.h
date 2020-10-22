#pragma once

#include <vector>

#include "perlin_noise.h"
#include "terrain.h"


class terrain_generator
{
    perlin_noise& perlin_noise_;

    std::vector<std::vector<float>> generate_heights(uint32_t grid_size);

protected:

    terrain_generator(perlin_noise& perlin_noise) : perlin_noise_(perlin_noise) { }

    virtual std::unique_ptr<terrain> build_terrain(std::vector<std::vector<float>> heights) = 0;

public:
    virtual ~terrain_generator() = default;

    std::unique_ptr<terrain> generate_terrain(uint32_t grid_size);
};
