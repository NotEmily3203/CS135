#include <iostream>
#include <cmath>
#include "decrypt.h"

char deShift(char c, int rshift){
    int ascii = int(c) - rshift;
    return ascii;
}

std::string decryptCaesar(std::string ciphertext, int rshift){
    std::string old_str;
    int length = ciphertext.length();
    for(int i = 0; i<length; i++){
        if(isalpha(ciphertext[i])){
            if(int(ciphertext[i])>=65 && int(ciphertext[i])<=90){
                if(int(ciphertext[i])-rshift < 65){
                    ciphertext[i] = deShift(ciphertext[i], -26);
                }
            }else if(int(ciphertext[i])>=97 && int(ciphertext[i])<=122){
                if(int(ciphertext[i])-rshift < 97){
                    ciphertext[i] = deShift(ciphertext[i], -26);
                }
            }
            old_str+=deShift(ciphertext[i], rshift);
        }else{
            old_str+=ciphertext[i];
        }
    }
    return old_str;
}
std::string decryptVigenere(std::string ciphertext, std::string keyword){
    std::string old_str;
    const int klength = keyword.length();
    int shift[klength];
    for(int i = 0; i < klength; i++){
        shift[i] = int(keyword[i]-97);
    }
    int plength = ciphertext.length();
    int index=0;
    for(int j = 0; j < plength; j++){ 
        if(isalpha(ciphertext[j])){
            if(index>=klength){
                do{
                    index-=klength;
                }while(index>=klength);
            }
            if(int(ciphertext[j])>=65 && int(ciphertext[j])<=90){
                if(int(ciphertext[j])-shift[index] < 65){
                    ciphertext[j] = deShift(ciphertext[j], -26);
                }
            }else if(int(ciphertext[j])>=97 && int(ciphertext[j])<=122){
                if(int(ciphertext[j])-shift[index] < 97){
                    ciphertext[j] = deShift(ciphertext[j], -26);
                }
            }
            old_str+=deShift(ciphertext[j], shift[index]);
            index++;
        }else{
            old_str+=ciphertext[j];
        }
    }
    return old_str;
}

double frequency(char letter, std::string encrypted_string){
    int length = encrypted_string.length();
    double frequency = 0;
    for(int i = 0; i<length; i++){
        if(tolower(encrypted_string[i]) == tolower(letter)){
            frequency++;
        }
    }
    frequency = frequency/length * 100;
    return frequency;
}

double distance(double * letter, double * encrypted){ //distance formula with 26 dimensions
    double result = 0;
    for(int i=0; i<26; i++){
        result += pow(letter[i]-encrypted[i],2);
    }
    result = sqrt(result);
    return result;
}

std::string solve(std::string encrypted_string){
    std::string result;
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    double letterFrequency[26] = {8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
    double encryptFrequency[26] = {};
    for(int i=0; i<26; i++){ // puts all frequency of letters in encrypted string into encryptFrequency array
        encryptFrequency[i] = frequency(letters[i], encrypted_string);
    }
    std::string rotated;
    int shift;
    double temp;
    double lowestDistance = distance(letterFrequency,encryptFrequency);
    for(int j=0; j<26; j++){
        rotated = decryptCaesar(encrypted_string, j);
        for(int k=0; k<26; k++){ // puts all frequency of letters in ROTATED string into encryptFrequency array
            encryptFrequency[k] = frequency(letters[k], rotated);
        }
        if(lowestDistance>distance(letterFrequency,encryptFrequency)){ // if new distance is lower, then the result might be that rotation!
            shift = j;
            lowestDistance = distance(letterFrequency,encryptFrequency);
            result = decryptCaesar(encrypted_string, shift);
        }
    }
    return result;
}