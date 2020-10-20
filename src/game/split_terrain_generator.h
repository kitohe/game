#pragma once

#include "terrain_generator.h"


class split_terrain_generator : public terrain_generator
{

    terrain_renderer renderer_;

public:
    split_terrain_generator(perlin_noise& perlin_noise) : terrain_generator(perlin_noise) { }

protected:
    terrain build_terrain(std::vector<std::vector<float>> heights) override;
};

