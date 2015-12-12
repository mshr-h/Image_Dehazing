#include "include/image.h"

void img_yuv_destruct(struct img_yuv_t *img)
{
    free(img->y[0]); free(img->y);
    free(img->u[0]); free(img->u);
    free(img->v[0]); free(img->v);
    free(img);
}
