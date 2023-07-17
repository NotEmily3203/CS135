#pragma once
#include <iostream>
char deShift(char c, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);

double frequency(char letter, std::string encrypted_string);
double distance(double * letter, double * encrypted);
std::string solve(std::string encrypted_string);