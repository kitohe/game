#include "terrain_generator.h"

std::vector<std::vector<float>> terrain_generator::generate_heights(uint32_t grid_size)
{
    std::vector<std::vector<float>> heights;

    for (int i = 0; i < grid_size + 1; i++)
    {
        heights.emplace_back(grid_size + 1);
        for (int j = 0; j < grid_size + 1; j++)
        {
            auto noise = perlin_noise_.get_perlin_noise(j, i);
            heights[i].push_back(noise);
        }
    }

    return heights;
}

terrain terrain_generator::generate_terrain(uint32_t grid_size)
{
    const auto heights = generate_heights(grid_size);
    return build_terrain(heights);
}
