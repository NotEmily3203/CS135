#include <iostream>
#include "lower.h"
std::string lower(int size){
    std::string triangle;
    int count = 0;
    for(int i=0;i<=size;i++){
        if(count!=size){
            for(int j=0;j<=count;j++){
                triangle+="*";
            }
            count+=1;
        }
        triangle+="\n";
    }
    return triangle;
}