/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E6.18

This program appends one vector to another
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b){
    std::vector<int> result;
    for(int i = 0; i<a.size(); i++){
        result.push_back(a[i]);
    }
    for(int j = 0; j<b.size(); j++){
        result.push_back(b[j]);
    }
    return result;
}