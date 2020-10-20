#pragma once

#include "terrain.h"
#include "camera.h"

class terrain;

class terrain_renderer
{
public:

    void render(const terrain* terrain, camera camera) const;
};
