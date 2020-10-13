#pragma once

#include "perlin_noise.h"


class terrain_generator
{
    perlin_noise& perlin_noise_;

public:

    terrain_generator(perlin_noise& perlin_noise) : perlin_noise_(perlin_noise) { }

    virtual void clean_up() = 0;
};

