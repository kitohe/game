#include "perlin_noise.h"


perlin_noise::perlin_noise(int seed, int octaves, float roughness, float amplitude)
{
    seed_ = seed;
    octaves_ = octaves;
    roughness_ = roughness;
    amplitude_ = amplitude;
}

perlin_noise::perlin_noise(int octaves, float roughness, float amplitude)
{
    seed_ = get_random_seed();
    octaves_ = octaves;
    roughness_ = roughness;
    amplitude_ = amplitude;
}

float perlin_noise::get_perlin_noise(int x, int y)
{
    float total = 0;
	float d = static_cast<float>(std::pow(2, octaves_ - 1));
	for (int i = 0; i < octaves_; i++) {
		float freq = static_cast<float>(std::pow(2, i) / d);
		float amp = static_cast<float>(std::pow(roughness_, i)) * amplitude_;
		total += get_interpolated_noise(x * freq, y * freq) * amp;
	}
	return total;
}

float perlin_noise::get_smooth_noise(int x, int y)
{
    float corners = (get_noise(x - 1, y - 1) + get_noise(x + 1, y - 1) + get_noise(x - 1, y + 1)
			+ get_noise(x + 1, y + 1)) / 16.0f;
	float sides = (get_noise(x - 1, y) + get_noise(x + 1, y) + get_noise(x, y - 1) + get_noise(x, y + 1)) / 8.0f;
	float center = get_noise(x, y) / 4.0f;
	return corners + sides + center;
}

float perlin_noise::get_noise(int x, int y)
{
    std::seed_seq seed { x * 49632 + y * 325176 + seed_};
    std::mt19937 engine(seed);
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    return dist(engine) * 2.0f - 1.0f;
}

float perlin_noise::get_interpolated_noise(float x, float y)
{
    int intX = static_cast<int>(x);
	float fracX = x - intX;
	int intY = static_cast<int>(y);
	float fracY = y - intY;

	float v1 = get_smooth_noise(intX, intY);
	float v2 = get_smooth_noise(intX + 1, intY);
	float v3 = get_smooth_noise(intX, intY + 1);
	float v4 = get_smooth_noise(intX + 1, intY + 1);
	float i1 = interpolate(v1, v2, fracX);
	float i2 = interpolate(v3, v4, fracX);
	return interpolate(i1, i2, fracY);
}

float perlin_noise::interpolate(float a, float b, float blend)
{
    double theta = blend * pi();
    float f = static_cast<float>((1.0f - std::cos(theta)) * 0.5f);
    return a * (1 - f) + b * f;
}

int perlin_noise::get_random_seed()
{
    std::seed_seq seed { rd_(), rd_(), rd_(), rd_(), rd_(), rd_(), rd_()};
    std::mt19937 engine(seed);
    std::uniform_int_distribution<int> dist(0, INT32_MAX);

    return dist(engine);
}
