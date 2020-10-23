#include "terrain_renderer.h"

void terrain_renderer::render(const terrain* terrain) const
{
    terrain->get_vao().bind();
    vao::currently_bound_vao();
    glDrawArrays(GL_TRIANGLES, 0, terrain->get_vertex_count());
    terrain->get_vao().unbind();
}
