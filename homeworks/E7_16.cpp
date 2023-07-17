/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E7.16

This program finds the distance between 2 points
*/

#include <iostream>
#include <cmath>
class Point{
public:
    double x;
    double y;
};

double distance(Point point1, Point point2){
    double result = sqrt((pow((point1.x - point2.x),2))+(pow((point1.y - point2.y),2)));
    return result;
}
int main(){
    Point a = {10,20};
    Point b = {-10,0};
    std::cout << distance(a, b) << '\n';
    return 0;
}