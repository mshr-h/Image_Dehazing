#include "include/image.h"

void arry_pix_destruct(struct arry_pix_t *arry_pix)
{
    free(arry_pix->elm);
    free(arry_pix);
}
