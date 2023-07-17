#include <iostream>
#include "funcs.h"
#include "imageio.h"


int main(){

    int image[MAX_H][MAX_W];
    int h, w;
    readImage("image1.pgm",image,h,w);
    invert(image, h, w);
    right_invert(image, h, w);
    white_box(image, h, w);
    frame(image, h, w);
    twice(image, h, w);
    blur(image, h, w);
}