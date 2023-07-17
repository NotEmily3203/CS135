#include <iostream>
#include "trapezoid.h"
std::string trapezoid(int width, int height){
    std::string result="";
    int out = 0;
    if(width-height<=height || width<=0 || height<=0){
        result="Impossible shape!";
    }else{
        for(int i = height; i>0; i--){
            for(int j=0; j<out; j++){
                result+=" ";
            }
            for(int k=0; k<width; k++){
                result+="*";
            }
            out+=1;
            width-=2;
            result+="\n";
        }
    }
    return result;
}