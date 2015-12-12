#include "include/image.h"

void map_destruct(struct map_t *map)
{
    free(map->data[0]); free(map->data);
    free(map);
}
