#include "vao.h"


void vao::bind() const
{
    glBindVertexArray(id_);
}

void vao::unbind() const
{
    glBindVertexArray(0);
}

void vao::link_attributes(std::vector<attribute>& attributes)
{
    attributes_ = attributes;

    for (const auto& attr : attributes)
    {
        attr.enable();
        attr.set_pointer(attr.get_offset(), attr.get_stride());
    }
}

void vao::init(const void* data, GLenum usage, std::vector<attribute>& attributes)
{

    vbo vbo(GL_FLOAT, usage);
    vbo.bind();
    vbo.alloc_and_store(sizeof(data), data);
    vbo.unbind();
    vbos_.push_back(vbo);

    link_attributes(attributes);
}

vao::~vao()
{
    glDeleteVertexArrays(1, &id_);
    for (const auto& vbo : vbos_)
    {
        vbo.remove();
    }
}
