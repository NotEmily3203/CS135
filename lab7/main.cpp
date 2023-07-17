#include <iostream>
#include "unindent.h"
#include "indent.h"
int main(){
    std::string correct = removeLeadingSpaces("corrupt.cpp");
    correct = indent(correct);
    std::cout<<correct;
    return 0;
}