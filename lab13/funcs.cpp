#include <iostream>
#include <cctype>
#include "funcs.h"
std::string printRange(int left, int right){
    if(right < left)
    {
        return "";
    }
    if(right >= left){
        return std::to_string(left) + " " + printRange(left+1, right);
    }
}
int sumRange(int left, int right){
    if(right < left){
        return 0;
    }
    if(right >= left){
        return left + sumRange(left+1, right);
    }
}
int sumArray(int *arr, int size){
    if(size <= 0){
        return 0;
    }else{
        return arr[size-1] + sumArray(arr, size-1);
    }
}
bool isAlphanumeric(std::string s){
    if(s.length() == 0){
        return true;
    }
    if(isalnum(s[s.length()-1])){
        return isAlphanumeric(s.substr(0, s.length() - 1));
    }else{
        return false;
    }
}
bool nestedParens(std::string s){
    if(s.length() == 0){
        return true;
    }
    if(s[0] == '(' && s[s.length() - 1] == ')'){
        return nestedParens(s.substr(1, s.length() - 2));
    }else{
        return false;
    }
}
