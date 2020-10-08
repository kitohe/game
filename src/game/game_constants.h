#pragma once


namespace game_constants
{
    constexpr int game_window_width = 1280;
    constexpr int game_window_height = 720;
    constexpr float game_window_aspect_ratio = static_cast<float>(game_window_width) / game_window_height;


    constexpr const char* cube_vertex_shader_path = R"(C:\Users\dmadr\Documents\Projects\CPP\game\src\game\shaders\cube_vertex_shader.glsl)";
    constexpr const char* cube_fragment_shader_path = R"(C:\Users\dmadr\Documents\Projects\CPP\game\src\game\shaders\cube_fragment_shader.glsl)";
}
