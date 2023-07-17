#include <iostream>


#include "funcs.h"

int main()
{
  std::cout<<"isDivisibleBy(100, 25): "<<isDivisibleBy(100, 25)<<std::endl
           <<"isDivisibleBy(34, 11): "<<isDivisibleBy(34, 11)<<std::endl
           <<"isPrime(2): "<<isPrime(2)<<std::endl
           <<"isPrime(15): "<<isPrime(15)<<std::endl
           <<"nextPrime(17): "<<nextPrime(17)<<std::endl
           <<"countPrimes(2,7): "<<countPrimes(2,7)<<std::endl
           <<"isTwinPrime(7): "<<isTwinPrime(7)<<std::endl
           <<"isTwinPrime(23): "<<isTwinPrime(23)<<std::endl
           <<"nextTwinPrime(37): "<<nextTwinPrime(37)<<std::endl
           <<"largestTwinPrime(1, 31): "<<largestTwinPrime(1, 31)<<std::endl;
  return 0;
}
