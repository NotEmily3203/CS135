/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E2.10 - Cost per 100 Miles

This program asks the user to input 3 items and prints out each items on a separate line
*/

#include <iostream>
using namespace std;
int main(){
    double gallons;
    double efficiency;
    double price;
    cout<<"Enter the number of gallons in the tank: ";
    cin>>gallons;
    cout<<"Enter the fuel efficiency in miles/gal: ";
    cin>>efficiency;
    cout<<"Enter price per gallon: $";
    cin>>price;
    double price_per_100 = (100/efficiency)*price;
    cout<<"The cost per 100 miles is $"<<price_per_100<<endl;
    double miles = efficiency*gallons;
    cout<<"This is how far you can go right now: "<<miles<<endl;
    return 0;
}