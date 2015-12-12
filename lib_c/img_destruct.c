#include "include/image.h"

void img_destruct(struct img_t *img)
{
    free(img->data[0]); free(img->data);
    free(img);
}
