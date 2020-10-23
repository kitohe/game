#pragma once

#include "terrain_generator.h"
#include "uniform_int.h"


class split_terrain_generator : public terrain_generator
{

    // temp
    std::unique_ptr<vao> vao_;
    std::unique_ptr<std::vector<attribute>> attrs_;

    terrain_renderer renderer_;

    int calculate_vertex_count(int grid_length) const;

    [[nodiscard]] std::vector<GLfloat> calculate_terrain_data(std::vector<std::vector<float>> heights);

    std::vector<glm::vec3> generate_quad_coords(int row, int col, const std::vector<std::vector<float>>& heights);

    std::vector<glm::vec3> get_triangle(const std::vector<glm::vec3>& coords, int idx_a, int idx_b, int idx_c);

    static glm::vec3 calculate_normal(glm::vec3 vert_0, glm::vec3 vert_1, glm::vec3 vert_2);

    static glm::vec3 sub_vec3(glm::vec3 vec_a, glm::vec3 vec_b);

    void add_triangle(std::vector<GLfloat>& data, std::vector<glm::vec3> vertices, glm::vec3 normal);

public:

    split_terrain_generator(perlin_noise& perlin_noise) : terrain_generator(perlin_noise) { }

protected:

    std::unique_ptr<terrain> build_terrain(std::vector<std::vector<float>> heights) override;
};
