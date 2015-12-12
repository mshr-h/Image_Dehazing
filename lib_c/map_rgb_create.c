#include "include/image.h"

struct map_rgb_t *map_rgb_create(int wt,int ht,double init)
{
    struct map_rgb_t *map;

    map=(struct map_rgb_t *)malloc(sizeof(struct map_rgb_t));

    map->wt=wt;
    map->ht=ht;

    map->r=Malloc2D_dbl(wt,ht,init);
    if(map->r==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    map->g=Malloc2D_dbl(wt,ht,init);
    if(map->g==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    map->b=Malloc2D_dbl(wt,ht,init);
    if(map->b==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    return map;
}
