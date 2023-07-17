/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E6.20

This program merges two sorted vectors
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

vector<int> merge_sorted(vector<int> a, vector<int> b){
    vector<int> result;
    vector<int> unsorted = append(a, b);
    int temp;
    for(int i = unsorted.size(); i>0; i--){
        temp = unsorted[i];
        for(int j = unsorted.size(); j>0; j--){
            if(temp < unsorted[j]){
                temp = unsorted[j];
            }
            result.push_back(unsorted[j]);
            unsorted.pop_back();
        }
    }
    return result;
}

int main(){
    
}