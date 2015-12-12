#include "include/image.h"

double **Malloc2D_dbl(int wt,int ht,double init)
{
    int h,w;
    double **x;

    x=(double **)malloc(sizeof(void *)*ht);
    if(x==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    x[0]=(double *)malloc(sizeof(double)*ht*wt);
    if(x[0]==NULL){
        printf("malloc failed (%s,%i)\n",__FILE__,__LINE__);
        exit(-1);
    }

    for(h=1;h<ht;h++){
        x[h]=x[h-1]+wt; /* + is a pointer summation */
    }
    for(h=0;h<ht;h++){
        for(w=0;w<wt;w++){
            x[h][w]=init;
        }
    }
    return x;
}
