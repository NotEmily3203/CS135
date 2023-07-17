
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

/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(std::string word, std::string definition, std::string pos);

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(std::string word, std::string definition, std::string pos);

/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(std::string word);

/*int main(){
    readWords("dict.txt");
    std::cout<<g_word_count<<std::endl;
    std::cout<<removeWord("Professor")<<std::endl;
    std::cout<<g_word_count<<std::endl;
    std::cout<<removeWord("Grumpy")<<std::endl;
    std::cout<<g_word_count<<std::endl;
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

bool addWord(std::string word, std::string definition, std::string pos){
    bool result = true;
    for(int i = 0; i < g_word_count; i++){
        if(word == g_words[i] || g_word_count==g_MAX_WORDS){
            return result = false;
        }
    }
    if(result == true){
        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = definition;
        g_word_count++;
    }
    return result;
}

bool editWord(std::string word, std::string definition, std::string pos){
    bool edit = false;
    int count;
    for(int i = 0; i<g_word_count; i++){
        if(word == g_words[i]){
            edit = true;
            count = getIndex(word);
        }
    }
    if(edit == true){
        g_pos[count] = pos;
        g_definitions[count] = definition;
    }
    return edit;
}

bool removeWord(std::string word){
    bool remove = false;
    int count;
    for(int i = 0; i<g_word_count; i++){
        if(word == g_words[i]){
            remove = true;
            count = getIndex(word);
        }
    }
    if(remove==true){
        g_words[count]="";
        g_pos[count]="";
        g_definitions[count]="";
        for(int j = count; j<=g_word_count; j++){
            g_words[j]=g_words[j+1];
            g_pos[j]=g_pos[j+1];
            g_definitions[j]=g_definitions[j+1];
        }
        g_word_count--;
    }
    return remove;
}