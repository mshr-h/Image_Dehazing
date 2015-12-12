#include "include/image_qt.h"

struct img_rgb_t *QImage_to_img_rgb(QImage *inImg)
{
    int h,w;
    struct img_rgb_t *out;
    QColor color;

    out=img_rgb_create(inImg->width(),inImg->height(),0);

    for(h=0;h<out->ht;h++){
        for(w=0;w<out->wt;w++){
            color=QColor(inImg->pixel(w, h));

            out->r[h][w]=color.red();
            out->g[h][w]=color.green();
            out->b[h][w]=color.blue();

        }
    }
    return out;
}
