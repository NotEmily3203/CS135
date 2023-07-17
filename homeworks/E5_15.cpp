/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E5.14

This program orders 3 alues from smallest to largest
*/
#include <iostream>
void sort2(int & a, int & b);
void sort3(int & a, int & b, int & c);
int main(){
    int a;
    int b;
    int c;
    std::cout<<"Enter first number: ";
    std::cin>>a;
    std::cout<<"Enter second number: ";
    std::cin>>b;
    std::cout<<"Enter third number: ";
    std::cin>>c;
    sort3(a,b,c);
    std::cout<<a<<b<<c;
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
void sort3(int & a, int & b, int & c){
    sort2(a,c);
    sort2(a,b);
    sort2(b,c);
    
}