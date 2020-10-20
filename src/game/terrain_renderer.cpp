#include "terrain_renderer.h"

void terrain_renderer::render(const terrain* terrain, camera camera) const
{
    terrain->get_vao().bind();
    terrain->render(camera);
    glDrawArrays(GL_TRIANGLES, 0, terrain->get_vertex_count());
    terrain->get_vao().unbind();
}
