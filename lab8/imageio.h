#pragma once

const int MAX_H = 512;
const int MAX_W = 512;
const int twiceMAX_H = 1024;
const int twiceMAX_W = 1024;

void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width); 
void taskE(std::string filename, int image[twiceMAX_H][twiceMAX_W], int height, int width);