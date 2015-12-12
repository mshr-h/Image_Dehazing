#include "include/image.h"

struct img_t *img_create(int wt,int ht,unsigned char init)
{
    struct img_t *img;

    img=(struct img_t *)malloc(sizeof(struct img_t));

    img->wt=wt;
    img->ht=ht;

    img->data=Malloc2D_uchr(wt,ht,init);
    if(img->data==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    return img;
}
