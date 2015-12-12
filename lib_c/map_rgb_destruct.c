#include "include/image.h"

void map_rgb_destruct(struct map_rgb_t *map)
{
    free(map->r[0]); free(map->r);
    free(map->g[0]); free(map->g);
    free(map->b[0]); free(map->b);

    free(map);
}
