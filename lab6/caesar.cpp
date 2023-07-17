#include <iostream>
#include <cctype>
#include "caesar.h"
char shiftChar(char c, int rshift){
    int ascii = int(c) + rshift;
    return ascii;
}
std::string encryptCaesar(std::string plaintext, int rshift){
    std::string new_string;
    int length = plaintext.length();
    for(int i = 0; i<length; i++){
        if(isalpha(plaintext[i])){
            if(int(plaintext[i])>=65 && int(plaintext[i])<=90){
                if(int(plaintext[i])+rshift > 90){
                    plaintext[i] = shiftChar(plaintext[i], -26);
                }
            }else if(int(plaintext[i])>=97 && int(plaintext[i])<=122){
                if(int(plaintext[i])+rshift > 122){
                    plaintext[i] = shiftChar(plaintext[i], -26);
                }
            }
            new_string+=shiftChar(plaintext[i], rshift);
        }else{
            new_string+=plaintext[i];
        }
    }
    return new_string;
}

