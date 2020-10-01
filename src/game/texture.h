#pragma once
#include <iostream>
#include <string>
#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


class texture
{
    int image_width;
    int image_height;
    unsigned char *image;
    GLuint texture_id;


public:
    texture(): image_width(0), image_height(0), image(nullptr)
    {
        stbi_set_flip_vertically_on_load(0);
    }

    void load(const std::string& filename);
    void generate_texture();
    void set_active(unsigned int texture_offset) const;
};
