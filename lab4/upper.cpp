#include <iostream>
#include "upper.h"
std::string upper(int size){
    std::string triangle="";
    int count = size;
    int space = 0;
    for(int i=size;i>0;i--){
        if(count!=0){
            for(int k=0;k<space;k++){
                triangle+=" ";
            }
            for(int j=0;j<count;j++){
                triangle+="*";
            }
            count-=1;
            space+=1;
        }
        triangle+="\n";
    }
    return triangle;
}