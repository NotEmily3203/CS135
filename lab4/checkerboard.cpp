#include <iostream>
#include "checkerboard.h"
std::string checkerboard(int width, int height){
    int width2 = width/2; //always rounds down
    int width1 = width - width2;
    int counter=height;
    std::string temp;
    std::string keys[2];
    std::string result;
    for(int i=0;i<width1;i++){
        temp+="* ";
    }
    keys[0] = temp;
    temp="";
    for(int j=0;j<width2;j++){
        temp+=" *";
    }
    keys[1] = temp;
    for(int k=0;k<height;k++){
        if(counter % 2 == 0){
            result+=keys[0];
        }else{
            result+=keys[1];
        }
        result+="\n";
        counter-=1;
    }
    return result;
}