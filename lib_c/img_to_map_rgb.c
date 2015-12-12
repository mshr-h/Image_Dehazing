#include "include/image.h"

struct map_rgb_t *img_to_map_rgb(struct img_rgb_t *in)
{
    int w,h;

    struct map_rgb_t *out;

    out=map_rgb_create(in->wt,in->ht,0);

    for(h=0;h<in->ht;h++){
        for(w=0;w<in->wt;w++){
            out->r[h][w]=(double)in->r[h][w]/255.0;
            out->g[h][w]=(double)in->g[h][w]/255.0;
            out->b[h][w]=(double)in->b[h][w]/255.0;
        }
    }

    return out;
}
