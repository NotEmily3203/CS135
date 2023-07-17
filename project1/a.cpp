/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 1 A
This creates a series of arrays that altogether, act like a dictionary
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <sstream>
const int g_MAX_WORDS = 1000;
int g_word_count = 0;

std::string g_words[g_MAX_WORDS];
std::string g_definitions[g_MAX_WORDS];
std::string g_pos[g_MAX_WORDS];
/*
    @param: The string with the `filename`
    @post:  Reads the words, definitions
            pos into the global-arrays 
            and set the value of `g_word_count`
            to the number of words read
*/
void readWords(std::string filename);
int main(){
    readWords("dict.txt");
    return 0;
}

void readWords(std::string filename){
    std::ifstream fin(filename);
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string line;
    std::string words, type;
    
    while(fin>>words>>type){
        g_words[g_word_count] = words;
        g_pos[g_word_count] = type;
        std::getline(fin ,g_definitions[g_word_count]);
        g_definitions[g_word_count] = g_definitions[g_word_count].substr(3);
        g_word_count++;
        
    }
    fin.close();
}