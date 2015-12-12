#include "include/image.h"

void img_rgb_destruct(struct img_rgb_t *img)
{
    free(img->r[0]); free(img->r);
    free(img->g[0]); free(img->g);
    free(img->b[0]); free(img->b);
    free(img);
}
