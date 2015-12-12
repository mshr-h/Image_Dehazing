#ifndef IMAGE_QT_H
#define IMAGE_QT_H

#include "include/image.h"
#include <QImage>
#include <QColor>

struct img_rgb_t *
QImage_to_img_rgb
(
    QImage *inImg
);

QImage
img_rgb_to_QImage
(
    struct img_rgb_t *img_rgb
);

#endif
