#include <iostream>
#include <fstream>
#include <sstream>
#include "indent.h"
int countChar(std::string line, char c){
    int occur;
    int length = line.length();
    for(int i=0; i<length; i++){
        if(line[i]==c){
            occur++;
        }
    }
    return occur;
}

std::string indent(std::string file){
    std::string newString;
    std::string line;
    int indent;
    std::istringstream in(file);
    while(std::getline(in, line)){
        int open = countChar(line,'{');
        int close = countChar(line,'}');
        for(int i=0; i<indent; i++){
            newString += "\t";
        }
        newString += line;
        newString += "\n";
        indent += open;
        indent -= close;
    }
    return newString;
}