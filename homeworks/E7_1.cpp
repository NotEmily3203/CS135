/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E6.8

This program sorts 2 values where the latter is the largest
*/

#include <iostream>
void sort2 (double * p, double * q){
    double r = *q;
    if(*p > *q){
        *q = *p;
        *p = r;
    }

}

int main(){
    double num1 = 5.7;
    double num2 = 3.2;
    double *a = &num1;
    double *b = &num2;
    sort2( a, b);
    return 0;
}