/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E7.18

This program finds the perimeter of a triangle
*/

#include <iostream>
#include <cmath>

class Point{
public:
    double x;
    double y;
};

class Triangle{
public:
    Point p1;
    Point p2;
    Point p3;
};

double distance(Point point1, Point point2){
    double result = sqrt((pow((point1.x - point2.x),2))+(pow((point1.y - point2.y),2)));
    return result;
}

double perimeter(Triangle t){
    double sum = 0;
    sum += distance(t.p1,t.p2);
    sum += distance(t.p2,t.p3);
    sum += distance(t.p3,t.p1);
    return sum;
}

int main(){
    Triangle a = {{1, 3},{5, 7},{2, 5}}; //(1, 3), (5, 7), (2, 5)
    std::cout << perimeter(a) << '\n';
    return 0;
}