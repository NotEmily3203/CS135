#include <iostream>
#include "box.h"
std::string box(int width, int height){
    std::string box = "";
    for(int i = 0; i < height; i++){
        for(int j = 0; j<width; j++){
            box = box + "*";
        }
        box = box + "\n";
    }
    return box;
}