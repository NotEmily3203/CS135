
//Author: Emily Lin
//Course: CSCI 13500
//Instructor: Genadiy Maryash
//Assignment: Project 1 B
//This retreives info from the dictionary


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

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/
int getIndex(std::string word);

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
std::string getDefinition(std::string word);

/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) 
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
std::string getPOS(std::string word);

/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/
int countPrefix(std::string prefix);

/*int main(){
    readWords("dict.txt");
    std::cout<<countPrefix("Pro")<<std::endl;
    return 0;
}*/

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

int getIndex(std::string word){
    int index = -1;
    for(int i = 0; i<g_word_count; i++){
        if(word == g_words[i]){
            index = i;
        }
    }
    return index;
}

std::string getDefinition(std::string word){
    std::string definition = "NOT_FOUND";
    for(int i = 0; i<g_word_count; i++){
        if(word == g_words[i]){
            definition = g_definitions[i];
        }
    }
    return definition;
}

std::string getPOS(std::string word){
    std::string pos = "NOT_FOUND";
    for(int i = 0; i<g_word_count; i++){
        if(word == g_words[i]){
            pos = g_pos[i];
        }
    }
    return pos;
}

int countPrefix(std::string prefix){
    int index = prefix.size();
    int count = 0;
    for(int i = 0; i<g_word_count;i++){
        if(g_words[i].substr(0,index) == prefix){
            count++;
        }
    }
    return count;
}