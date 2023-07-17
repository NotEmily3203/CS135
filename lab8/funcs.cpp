#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include "imageio.h"
#include "funcs.h"

void invert(int image[MAX_H][MAX_W], int h, int w){
    int inverted[MAX_H][MAX_W];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            inverted[i][j] = 255 - image[i][j];
        }
    }
    writeImage("taskA.pgm", inverted, h, w);
}

void right_invert(int image[MAX_H][MAX_W], int h, int w){
    int right_inverted[MAX_H][MAX_W];
    int widthHalf = w/2;
    for(int i=0;i<h;i++){
        for(int j=0;j<widthHalf;j++){
            right_inverted[i][j] =image[i][j];
        }
        for(int k=widthHalf;k<w;k++){
            right_inverted[i][k] = 255 - image[i][k];
        }
    }
    writeImage("taskB.pgm", right_inverted, h, w);
}

void white_box(int image[MAX_H][MAX_W], int h, int w){
    int white_boxed[MAX_H][MAX_W];
    int widthFourth = w/4;
    int heightFourth = h/4;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if((i>=heightFourth && i<=h-heightFourth) && (j>=widthFourth && j<=w-widthFourth)){
                white_boxed[i][j]=255;
            }else{
                white_boxed[i][j]=image[i][j];
            }
        }
    }
    writeImage("taskC.pgm", white_boxed, h, w);
}

void frame(int image[MAX_H][MAX_W], int h, int w){
    int framed[MAX_H][MAX_W];
    int widthFourth = w/4;
    int heightFourth = h/4;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if((i==heightFourth || i==h-heightFourth)&&(j>=widthFourth && j<=w-widthFourth)){
                framed[i][j]=255;
            }else if((j==widthFourth || j==w-widthFourth)&&(i>=heightFourth && i<=h-heightFourth)){
                framed[i][j]=255;
            }else{
                framed[i][j]=image[i][j];
            }
        }
    }
    writeImage("taskD.pgm", framed, h, w);
}

void twice(int image[MAX_H][MAX_W], int h, int w){
    int newimage[twiceMAX_H][twiceMAX_W];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            newimage[i*2][j*2] = image[i][j];
            newimage[i*2][j*2+1] = image[i][j];
            newimage[i*2+1][j*2] = image[i][j];
            newimage[i*2+1][j*2+1] = image[i][j];
        }
    }
    taskE("taskE.pgm", newimage, 2*h, 2*w);
}

void blur(int image[MAX_H][MAX_W], int h, int w){
    int blurred[MAX_H][MAX_W];
    for(int i=0;i<h;i+=2){
        for (int j=0;j<w;j+=2){
			int avg = (image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1])/4;
            blurred[i][j] = avg;
            blurred[i][j+1] = avg;
            blurred[i+1][j] = avg;
            blurred[i+1][j+1] = avg;
        }
    }
    writeImage("taskF.pgm", blurred, h, w);
}
