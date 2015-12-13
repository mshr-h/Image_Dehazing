#include "include/image.h"
#include "include/image_qt.h"

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("./Image_Dehazing hazyimage.png out.png\n");
        return 0;
    }

    auto in=QImage_to_img_rgb(new QImage(argv[1]));

    double omega=0.95;
    double t0=0.01;
    double p=0.1;

    auto out=Dehaze(in,omega,t0,p);

    auto outImg=img_rgb_to_QImage(out);

    outImg.save(argv[2], "PNG");

    img_rgb_destruct(in);
    img_rgb_destruct(out);

    return 0;
}
