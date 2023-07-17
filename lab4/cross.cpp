#include <iostream>
#include "cross.h"
std::string cross(int size){
    std::string temp;
    std::string result;
    int outspace=0;
    int inspace=size;
    const int max = size/2;
    std::string rows[max];
    for(int i=0;i<max;i++){
        for(int j=0;j<outspace;j++){
            temp+=" ";
        }
        if(outspace<size){
            outspace+=1;
        }
        temp+="*";
        inspace-=2;
        for(int k=0;k<inspace;k++){
            temp+=" ";
        }
        temp+="*";
        rows[i]=temp;
        temp+="";
        temp="";
    }
    for(int l=0;l<max;l++){
        result+=rows[l];
        result+="\n";
    }
    for(int m=max-1;m>=0;m--){
        result+=rows[m];
        result+="\n";
    }
    return result;
}