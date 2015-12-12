#include "include/image.h"

struct img_yuv_t *img_rgb_to_yuv(struct img_rgb_t *img_rgb)
{
    int w,h;

    struct img_yuv_t *out;

    out=img_yuv_create(img_rgb->wt,img_rgb->ht,0);

    for(h=0;h<img_rgb->ht;h++){
        for(w=0;w<img_rgb->wt;w++){
            out->y[h][w]=( ( 66*img_rgb->r[h][w]+129*img_rgb->g[h][w]+25*img_rgb->b[h][w]+128)>>8 )+16;
            out->u[h][w]=( (-38*img_rgb->r[h][w]-74*img_rgb->g[h][w]+112*img_rgb->b[h][w]+128)>>8 )+128;
            out->v[h][w]=( (112*img_rgb->r[h][w]-94*img_rgb->g[h][w]-18*img_rgb->b[h][w]+128)>>8 )+128;
        }
    }

    return out;
}
