#include "include/image.h"

struct img_rgb_t *Dehaze
(
    struct img_rgb_t *in,
    double omega,
    double t0,
    double p
)
{
    struct img_rgb_t *out;
    out=img_rgb_create(in->wt,in->ht,0);
    return out;
}
