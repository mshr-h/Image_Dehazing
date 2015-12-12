#include "include/image.h"

struct arry_pix_t *arry_pix_create(unsigned long num_of_pixs)
{
    struct arry_pix_t *arry;

    arry=(struct arry_pix_t *)malloc(sizeof(struct arry_pix_t));

    arry->elm=(struct pix_t *)malloc((num_of_pixs)*sizeof(struct pix_t));;
    if(arry->elm==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }
    arry->num_of_pixs=num_of_pixs;

    return arry;
}
