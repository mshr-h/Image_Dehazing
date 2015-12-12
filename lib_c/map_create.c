#include "include/image.h"

struct map_t *map_create(int wt,int ht,double init)
{
    struct map_t *map;

    map=(struct map_t *)malloc(sizeof(struct map_t));

    map->wt=wt;
    map->ht=ht;

    map->data=Malloc2D_dbl(wt,ht,init);
    if(map->data==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    return map;
}
