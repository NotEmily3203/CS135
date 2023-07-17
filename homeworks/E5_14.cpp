/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E5.14

This program swaps 2 values if the second value is greater
*/
#include <iostream>
void sort2(int & a, int & b);
int main(){
    int a;
    int b;
    std::cout<<"Enter first number: ";
    std::cin>>a;
    std::cout<<"Enter second number: ";
    std::cin>>b;
    sort2(a,b);
    return 0;
}
void sort2(int & a, int & b){
    int x;
    if(a>b){
        x = a,
        a = b;
        b = x;
    }
}