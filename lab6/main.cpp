#include <iostream>
#include <cctype>
#include <cmath>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  std::cout<<encryptCaesar("Hello, World!", 10)<<std::endl;
  std::cout<<encryptVigenere("Hello, World!", "cake")<<std::endl;
  std::cout<<decryptVigenere("Jevpq, Wyvnd!", "cake")<<std::endl;
  std::cout<<decryptCaesar("Rovvy, Gybvn!", 10)<<std::endl;
  std::cout<<solve(encryptCaesar("I loathe bread. Bread is bready so I hate it", 10))<<std::endl;
  std::cout<<solve(encryptCaesar("Cats are so awesome and adorable and weird!", 10))<<std::endl;
  return 0;
}
