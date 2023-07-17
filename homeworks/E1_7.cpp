/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E1.7 - Three Items

This program asks the user to input 3 items and prints out each items on a separate line
*/
#include <iostream>
using namespace std;
int main(){
    string items[3];
    for(int i=0; i<3; i++){
        cout<<"Enter an item: "<<endl;
        getline(cin,items[i]);
    }
    for(int i=0; i<3; i++){
        cout<<items[i]<<"\n";
    }
    return 0;
}