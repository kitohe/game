#include "master_renderer.h"


void master_renderer::prepare() const
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void master_renderer::render(camera& cam) const
{
    prepare();
    cam.update(window_.get_mouse_x_pos(), window_.get_mouse_y_pos());
}
