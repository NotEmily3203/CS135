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
#include <stdlib.h>
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

std::string getRandomWord();

/*
    @param            :   The string with a word from the dictionary 
    @return           :   string of "_" based on the number of
                          characters in the given `word` 
    @post             :   Return string of "_" based on the length
                          of the given `word`.
                          For example, if the word is "game", then
                          the function would return "____". In other
                          words, a string of four "_"s.
*/
std::string maskWord(std::string word);

/*
    @param            :   The integer for the difficulty of the game
                          (0 for easy, 1 for normal, and 2 for hard) 
    @return           :   The number of tries given the `difficulty`
                          (9 for easy, 7 for normal, and 5 for hard)
    @post             :   Return the number of tries based on given
                          difficulty (0-easy: 9 tries, 1-normal: 7
                          tries, 2-Hard: 5 tries) 
*/
int getTries(int difficulty);

/*
    @param tries      :   The integer for remaining tries 
    @param difficulty :   The integer for the difficulty of the game 
                          (0 for easy, 1 for normal, and 2 for hard) 
    @post             :   prints the number of lives left and number
                          of lives used using "O" and "X". DO NOT
                          PRINT AN ENDLINE

    For example : calling `printAttemps(2, 1)` would print "OOXXXXX". 
                  Based on given `difficulty`, we know the total tries
                  is 7 (from `getTries(1)`). Also, the player has 2
                  `tries` remaining based on the given parameter.
                  Therefore, the function prints two "0"s to indicate
                  the remaining tries and 5 "X"s to indicate the tries
                  that have been used (7-2=5)          
*/
void printAttempts(int tries, int difficulty);

/*
    @param word       :   The string word from the dictionary
    @param letter     :   The char letter that that will be revealed
    @param(&) current :   The string representing a masked word
    @return           :   `true` if the `letter` exists in `word`,
                          otherwise return `false`  
    @post             :   If the given `letter` exists in `word`
                          reveal the `letter` in `current` masked word
                          and return `true`. Otherwise, return `false`

    For example : Let's say we have the following main function:
                  int main(){
                      string w = "g___";
                      cout << revealLetter("good", 'o', "g___") << endl;
                      cout <<  w << endl;
                  }
                  The first `cout` will print 1 because the letter 'o'
                  exists in "good". Thus, the function returned `true`.
                  The second `cout` will print "goo_". The variable `w`
                  has been modified by the function to reveal all the
                  `o`s in "good" resulting in "goo_"           
*/
bool revealLetter(std::string word, char letter, std::string &current);

void gameLoop();

/*int main(){
    readWords("dict.txt");
    printAttempts(2,1);
    printAttempts(1,1);
    printAttempts(0,1);
    printAttempts(9,0);
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

std::string getRandomWord(){
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

std::string maskWord(std::string word){
    std::string blank;
    int count = word.length();
    for(int i=0; i<count; i++){
        blank +="_";
    }
    return blank;
}

int getTries(int difficulty){
    int tries;
    if(difficulty == 0){
        tries = 9;
    }else if(difficulty == 1){
        tries = 7;
    }else if(difficulty == 2){
        tries = 5;
    }
    return tries;
}

void printAttempts(int tries, int difficulty){ //idk why this is mot working
    int lives_left = getTries(difficulty)- tries;
    for(int i=0; i < tries; i++){
        std::cout << "O";
    }
    for(int j=0; j < lives_left; j++){
        std::cout << "X";
    }
}

bool revealLetter(std::string word, char letter, std::string &current){
    bool reveal = false;
    int length = word.length();
    for(int i = 0; i<length; i++){
        if(letter == word[i]){
            current[i] = letter;
            bool reveal = true;
        }
    }
    return reveal;
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    std::string word, current;
    char letter;
    while (true) {
        std::cout << "Welcome to Hangman!" << std::endl;
        std::cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        std::cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            std::cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            std::cin >> difficulty;
        }
        if (difficulty == 3) {
            std::cout << "If you're hangry, go grab a bite! See what I did there?" << std::endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            std::cout << "Life: ";
            printAttempts(tries, difficulty);
            std::cout << std::endl << "Word: "<< current << std::endl;
            std::cout << "Enter a letter: ";
            std::cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                std::cout << "The part of speech of the word is "<< getPOS(word) << std::endl;
            }
            if (tries == 1) {
                std::cout << "Definition of the word: " << getDefinition(word) << std::endl;
            }
        }
        if (tries == 0) {
            std::cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << std::endl;
        }
        else {
            std::cout << "Congrats!!!" << std::endl;
        }
    }
}