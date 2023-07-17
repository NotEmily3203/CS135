/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E5.6

This program finds the middle char of a string if the length is odd
and the two middle chars if it is even
*/
#include <iostream>
#include <cstring>
std::string middle(std::string word);
int main(){
    std::string word;
    std::cout<<"Enter a word: "<<std::endl;
    std::cin>>word;
    std::cout<<middle(word)<<std::endl;
    return 0;
}
std::string middle(std::string word){
    std::string mid;
    int count = word.size();
    int half = count/2;
    if(count % 2 == 1){
        mid = word.substr(half, 1);
    }else{
        mid = word.substr(half-1, 2);
    }
    return mid;
}