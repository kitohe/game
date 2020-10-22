#include "split_terrain_generator.h"

// grid_length - 1 : actual grid_length
// 2 : triangles in square
// 3 : vertices in triangle
int split_terrain_generator::calculate_vertex_count(int grid_length) const
{
    return (grid_length - 1) * (grid_length - 1) * 2 * 3;
}

std::vector<GLfloat> split_terrain_generator::calculate_terrain_data(std::vector<std::vector<float>> heights)
{
    std::vector<GLfloat> data;

    for (int i = 0; i < heights.size() - 1; i++)
    {
        for (int j = 0; j < heights[i].size() - 1; j++)
        {
            auto coords = generate_quad_coords(i, j, heights);

            auto top_left_triangle = get_triangle(coords, 0, 1, 2);
            auto top_left_normal = calculate_normal(top_left_triangle[0], top_left_triangle[1], top_left_triangle[2]);
            
            auto bot_right_triangle = get_triangle(coords, 2, 1, 3);
            auto bot_right_normal= calculate_normal(bot_right_triangle[2], bot_right_triangle[1], bot_right_triangle[3]);

            // TODO: Add colors later
            add_triangle(data, top_left_triangle, top_left_normal);
            add_triangle(data, bot_right_triangle, bot_right_normal);
        }
    }

    return data;
}

std::vector<glm::vec3> split_terrain_generator::generate_quad_coords(int row, int col,
    const std::vector<std::vector<float>>& heights)
{
    // one vertex is XYZNNNRGBA
    std::vector<glm::vec3> quad_positions(4);
    quad_positions[0] = glm::vec3(col, heights[row][col], row);
    quad_positions[1] = glm::vec3(col, heights[row + 1][col], row + 1);
    quad_positions[2] = glm::vec3(col + 1, heights[row][col + 1], row);
    quad_positions[3] = glm::vec3(col + 1, heights[row + 1][col + 1], row + 1);

    return quad_positions;
}

terrain split_terrain_generator::build_terrain(std::vector<std::vector<float>> heights)
{
    int vetex_count = calculate_vertex_count(heights.size());
    auto terr = calculate_terrain_data(heights);

    attribute pos(0, 3, GL_FLOAT, 8 * sizeof(GLfloat), 0);
    attribute normals(1, 3, GL_FLOAT, 8 * sizeof(GLfloat), 3);
    attribute tex_coords(2, 3, GL_FLOAT, 8 * sizeof(GLfloat), 6);

    std::vector<attribute> attrs { pos, normals, tex_coords };

    vao vao(attrs);
    vao.create(GL_STATIC_DRAW, terr.size() * sizeof(GLfloat), &terr);
    return terrain(vao, renderer_, vetex_count);
}

std::vector<glm::vec3> split_terrain_generator::get_triangle(const std::vector<glm::vec3>& coords, int idx_a, int idx_b,
    int idx_c)
{
    return std::vector<glm::vec3> { coords[idx_a], coords[idx_b], coords[idx_c] };
}

glm::vec3 split_terrain_generator::calculate_normal(glm::vec3 vert_0, glm::vec3 vert_1, glm::vec3 vert_2)
{
    auto tan_a = sub_vec3(vert_1, vert_0);
    auto tan_b = sub_vec3(vert_2, vert_0);
    auto normal = glm::cross(tan_a, tan_b);
    return glm::normalize(normal);
}

glm::vec3 split_terrain_generator::sub_vec3(glm::vec3 vec_a, glm::vec3 vec_b)
{
    return glm::vec3(vec_b[0] - vec_a[0],
                     vec_b[1] - vec_a[1],
                     vec_b[2] - vec_a[2]);
}

void split_terrain_generator::add_triangle(std::vector<GLfloat>& data, std::vector<glm::vec3> vertices,
    glm::vec3 normal)
{
    // this should produce xyznnnrgb, hopefully

    for (int i = 0; i < vertices.size(); i++)
    {
        data.push_back(vertices[i][0]);
        data.push_back(vertices[i][1]);
        data.push_back(vertices[i][2]);
    }

    data.push_back(normal[0]);
    data.push_back(normal[1]);
    data.push_back(normal[2]);

    // DO COLORS LATER, WHITE FOR NOW
    data.push_back(1.0f);
    data.push_back(1.0f);
    data.push_back(1.0f);
}
