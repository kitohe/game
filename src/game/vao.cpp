#include "vao.h"


void vao::bind() const
{
    glBindVertexArray(id_);
}

void vao::unbind() const
{
    glBindVertexArray(0);
}

void vao::create(GLenum usage, int data_size, const void* data)
{
    if (attributes_.empty())
    {
        std::cerr << "Cannot create VAO without attributes!" << std::endl;
        return;
    }

    if (data == nullptr)
    {
        std::cerr << "Data does not exist!" << std::endl;
        return;
    }

    bind(); // I'm retarded

    const std::shared_ptr<vbo> local_vbo = std::make_shared<vbo>(GL_ARRAY_BUFFER, usage);
    
    local_vbo->bind();
	local_vbo->alloc_and_store(data_size, data);
    vbos_.push_back(local_vbo);
    link_attributes();
    local_vbo->unbind();

    unbind();
}

void vao::currently_bound_vao()
{
    GLint curr_vao;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &curr_vao);
    std::cout << "Currently bound VAO id: " << curr_vao << std::endl;
}

vao::~vao()
{
    glDeleteVertexArrays(1, &id_);
    for (const auto& vbo : vbos_)
    {
        vbo->remove();
    }
}
