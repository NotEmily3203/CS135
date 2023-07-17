#include <iostream>
#include "checkerboard3x3.h"
std::string checkerboard3x3(int width, int height){
    std::string temp;
    std::string keys[2];
    std::string result;
    int row_count = width;
    int col_count = height;
    while(row_count>0){
        for(int i=0;i<3;i++){
            temp+="*";
            row_count-=1;
        }
        for(int j=0;j<3;j++){
            temp+=" ";
            row_count-=1;
        }
    }
    temp=temp.substr(0,width);
    keys[0]=temp;
    temp="";
    row_count = width;
    while(row_count>0){
        for(int i=0;i<3;i++){
            temp+=" ";
            row_count-=1;
        }
        for(int j=0;j<3;j++){
            temp+="*";
            row_count-=1;
        }
    }
    temp=temp.substr(0,width);
    keys[1]=temp;
    while(col_count>0){
        for(int k=0;k<3;k++){
            result+=keys[0];
            result+="\n";
            col_count-=1;
            if(col_count<1){
                break;
            }
        }
        if(col_count<1){
                break;
            }
        for(int l=0;l<3;l++){
            result+=keys[1];
            result+="\n";
            col_count-=1;
            if(col_count<1){
                break;
            }
        }
    }
    return result;
}