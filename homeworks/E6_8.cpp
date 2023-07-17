/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E6.8

This program orders 3 alues from smallest to largest
*/
#include <iostream>
bool equals(int a[], int a_size, int b[], int b_size);
int main(){
    int a1[4] = {1,2,3,4};
    int a2[5] = {1,2,3,4,5};
    bool equal = equals(a1,4,a2,5);
    std::cout<<equal<<std::endl;
    return 0;
}
bool equals(int a[], int a_size, int b[], int b_size){
    bool x = false;
    if(a_size == b_size){
        for(int i=0; i<a_size;i++){
            if(a[i] == b[i]){
                x = true;
            }else{
                x = false;
                break;
            }
        }
    }
    return x;
}