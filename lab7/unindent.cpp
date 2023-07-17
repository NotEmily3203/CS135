#include <iostream>
#include <fstream>
#include <cctype>
#include "unindent.h"
std::string removeLeadingSpaces(std::string filename){
    std::string newString;
    std::ifstream fin(filename);
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string line;
    while(std::getline(fin, line)){
        int length = line.length();
        bool add = false;
        for(int i=0; i<length; i++){
            if(!isspace(line[i])){
                add = true;
            }
            if(add == true){
                newString += line[i];
            }
        }
        newString +="\n";
    }
    return newString;
}