#include "terrain.h"

void terrain::render(camera camera) const
{
    renderer_.render(this, camera);
}
