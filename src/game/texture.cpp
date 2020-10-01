#include "texture.h"

void texture::load(const std::string& filename)
{
    image = stbi_load(filename.c_str(), &image_width, &image_height, 0, 3);

    if (!image)
        std::cerr << "Error while loading texture from: " << filename << std::endl;
}

void texture::generate_texture()
{
    if (!image)
    {
        std::cerr << "Error while generating texture. Image was nullptr" << std::endl;
        return;
    }

    glGenTextures(1, &texture_id);
    glActiveTexture(GL_TEXTURE0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void texture::set_active(const unsigned int texture_offset) const
{
    glActiveTexture(GL_TEXTURE0 + texture_offset);
    glBindTexture(GL_TEXTURE_2D, texture_id);
}
