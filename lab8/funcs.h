#pragma once
#include <iostream>
#include "imageio.h" 
void invert(int image[MAX_H][MAX_W], int h, int w);
void right_invert(int image[MAX_H][MAX_W], int h, int w);
void white_box(int image[MAX_H][MAX_W], int h, int w);
void frame(int image[MAX_H][MAX_W], int h, int w);
void twice(int image[MAX_H][MAX_W], int h, int w);
void blur(int image[MAX_H][MAX_W], int h, int w);