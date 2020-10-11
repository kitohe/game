#pragma once

#include <random>
#include <cmath>


class perlin_noise
{
    int seed_;
    int octaves_;
    float roughness_;
    float amplitude_;

    std::random_device rd_;

public:
    perlin_noise(int seed, int octaves, float roughness, float amplitude);

    perlin_noise(int octaves, float roughness, float amplitude);

    int get_seed() const { return seed_; }

    float get_amplitude() const { return amplitude_; }

    float get_perlin_noise(int x, int y);

private:

    float get_smooth_noise(int x, int y);

    float get_noise(int x, int y);

    float get_interpolated_noise(float x, float y);

    float interpolate(float a, float b, float blend);

    int get_random_seed();

    double pi() const { return std::atan(1) * 4; }
};
