#include "include/image.h"

unsigned char **Malloc2D_uchr(int wt,int ht,unsigned char init)
{
    int h,w;
    unsigned char **m;

    m=(unsigned char **)malloc(sizeof(void *)*ht);
    if(m==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }
    m[0]=(unsigned char *)malloc(sizeof(unsigned char)*ht*wt);
    if(m[0]==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    for(h=1;h<ht;h++){
        m[h]=m[h-1]+wt;
    }
    for(h=0;h<ht;h++){
        for(w=0;w<wt;w++){
            m[h][w]=init;
        }
    }

    return m;
}
