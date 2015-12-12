#include "include/image.h"

struct img_rgb_t *img_rgb_create(int wt,int ht,unsigned char init)
{
    struct img_rgb_t *img;

    img=(struct img_rgb_t *)malloc(sizeof(struct img_rgb_t));

    img->wt=wt;
    img->ht=ht;

    img->r=Malloc2D_uchr(wt,ht,init);
    if(img->r==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    img->g=Malloc2D_uchr(wt,ht,init);
    if(img->g==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    img->b=Malloc2D_uchr(wt,ht,init);
    if(img->b==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    return img;
}
