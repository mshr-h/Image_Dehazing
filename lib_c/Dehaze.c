#include "include/image.h"

struct img_rgb_t *Dehaze
(
    struct img_rgb_t *in,
    double omega,
    double t0,
    double p
)
{

    int i,h,w,lh,lw;
    unsigned char min_ri,min_gi,min_bi;
    double min_r,min_g,min_b,min_t;
    double r,g,b,t_;
    int max_y,max_val;
    int num_of_pix=(int)((in->ht)*(in->wt)*p)/100;

    struct pix_t cntr,pos;
    struct clr_t airlight;
    struct img_t *drk_ch;
    struct arry_pix_t *array_pix;
    struct img_yuv_t *in_yuv;
    struct map_t *tmap;
    struct img_rgb_t *out;

    cntr.w=DRK_CH_WND_WT/2;
    cntr.h=DRK_CH_WND_HT/2;

    drk_ch=img_create(in->wt,in->ht,0);
    array_pix=arry_pix_create(num_of_pix);
    in_yuv=img_rgb_to_yuv(in);
    tmap=map_create(in->wt,in->ht,1.0);
    out=img_rgb_create(in->wt,in->ht,0);

    // compute the dark channel from input image
    for(h=0;h<in->ht;h++){
        for(w=0;w<in->wt;w++){
            min_ri=255;
            min_gi=255;
            min_bi=255;
            for(lh=-cntr.h;lh<=cntr.h;lh++){
                for(lw=-cntr.w;lw<=cntr.w;lw++){
                    if((w+lw)>=0&&(w+lw)<in->wt-1&&(h+lh)>=0&&(h+lh)<in->ht-1){
                        min_ri=MIN(min_ri,in->r[h+lh][w+lw]);
                        min_gi=MIN(min_gi,in->g[h+lh][w+lw]);
                        min_bi=MIN(min_bi,in->b[h+lh][w+lw]);
                    }
                }
            }
            drk_ch->data[h][w]=MIN(MIN(min_ri,min_gi),min_bi);
        }
    }

    // pick up the top p% brightest pixels in the dark channel
    max_val=255;
    for(i=0;i<num_of_pix;){
        for(h=0;h<in->ht;h++){
            for(w=0;w<in->wt;w++){
                if(drk_ch->data[h][w]==max_val){
                    array_pix->elm[i].h=h;
                    array_pix->elm[i].w=w;
                    i++;
                }
                if(i==num_of_pix)
                    break;
            }
            if(i==num_of_pix)
                break;
        }
        if(i==num_of_pix)
            break;
        max_val--;
    }

    // find the airlight which has the hightest intensity in the input image
    max_y=0;
    for(i=0;i<num_of_pix;i++){
        if(max_y<in_yuv->y[array_pix->elm[i].h][array_pix->elm[i].w]){
            pos=array_pix->elm[i];
            max_y=in_yuv->y[pos.h][pos.w];
        }
    }
    airlight.r=in->r[pos.h][pos.w];
    airlight.g=in->g[pos.h][pos.w];
    airlight.b=in->b[pos.h][pos.w];

    // compute the transmission map
    for(h=0;h<in->ht;h++){
        for(w=0;w<in->wt;w++){
            min_r=255.0;
            min_g=255.0;
            min_b=255.0;
            for(lh=-cntr.h;lh<=cntr.h;lh++){
                for(lw=-cntr.w;lw<=cntr.w;lw++){
                    if((lw+w)>=0&&(w+lw)<in->wt-1&&(h+lh)>=0&&(h+lh)<in->ht-1){
                        min_r=MIN(min_r,(double)in->r[h+lh][w+lw]/airlight.r);
                        min_g=MIN(min_g,(double)in->g[h+lh][w+lw]/airlight.g);
                        min_b=MIN(min_b,(double)in->b[h+lh][w+lw]/airlight.b);
                    }
                }
            }
            min_t=MIN(MIN(min_r,min_g),min_b);
            tmap->data[h][w]=1-omega*min_t;
        }
    }

    // compute the haze free image
    for(h=0;h<in->ht;h++){
        for(w=0;w<in->wt;w++){
            t_=MAX(tmap->data[h][w],t0);

            r=(((double)in->r[h][w]-airlight.r)/t_)+airlight.r;
            g=(((double)in->g[h][w]-airlight.g)/t_)+airlight.g;
            b=(((double)in->b[h][w]-airlight.b)/t_)+airlight.b;

            out->r[h][w]=(unsigned char)MIN(MAX(r,0),255);
            out->g[h][w]=(unsigned char)MIN(MAX(g,0),255);
            out->b[h][w]=(unsigned char)MIN(MAX(b,0),255);
        }
    }

    img_yuv_destruct(in_yuv);
    img_destruct(drk_ch);
    arry_pix_destruct(array_pix);
    map_destruct(tmap);

    return out;
}
