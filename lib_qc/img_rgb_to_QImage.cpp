#include "include/image_qt.h"

QImage img_rgb_to_QImage(struct img_rgb_t *img_rgb)
{
    int h,w;

    QImage outImg(img_rgb->wt,img_rgb->ht,QImage::Format_RGB888);

    for(h=0;h<img_rgb->ht;h++){
        for(w=0;w<img_rgb->wt;w++){
            outImg.setPixel(w,h,qRgb((int)img_rgb->r[h][w],
                                     (int)img_rgb->g[h][w],
                                     (int)img_rgb->b[h][w]) );
        }
    }
    return outImg;
}
