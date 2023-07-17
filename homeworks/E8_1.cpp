/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Homework E8.1

This program creates hello.txt and enters Hello, World! then reads the file into a string
*/
#include <iostream>
#include <fstream>
int main(){
    std::ofstream fout("hello.txt");
    fout<<"Hello, World!";
    fout.close();
    std::fstream fin("hello.txt");
    std::string words;
    std::getline(fin,words);
    std::cout<<words<<std::endl;
    return 0;
}