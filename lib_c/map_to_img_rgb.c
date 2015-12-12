#include "include/image.h"

struct img_rgb_t *map_to_img_rgb(struct map_rgb_t *map)
{
    int w,h;

    struct img_rgb_t *out;

    out=img_rgb_create(map->wt,map->ht,0);

    for(h=0;h<map->ht;h++){
        for(w=0;w<map->wt;w++){
            out->r[h][w]=(unsigned char)(255.0*map->r[h][w]);
            out->g[h][w]=(unsigned char)(255.0*map->g[h][w]);
            out->b[h][w]=(unsigned char)(255.0*map->b[h][w]);
        }
    }

    return out;
}
