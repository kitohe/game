#pragma once
#include <iostream>
#include <string>
#include <glad/glad.h>


class texture
{
    int image_width;
    int image_height;
    unsigned char *image;
    GLuint texture_id;
    

public:
    texture();

    void load(const std::string& filename);
    void generate_texture();
    void set_active(unsigned int texture_offset) const;
};
