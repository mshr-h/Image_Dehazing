#include "include/image.h"

struct img_rgb_t *Dehaze
(
    struct img_rgb_t *img_rgb,
    double omega
)
{
    struct img_rgb_t *out;
    out=img_rgb_create(img_rgb->wt,img_rgb->ht,0);
    return out;
}
