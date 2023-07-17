#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("Divisible Cases"){
    CHECK(isDivisibleBy(100, 25)==true);
    CHECK(isDivisibleBy(33, 11)==true);
}

TEST_CASE("Indivisible Cases"){
    CHECK(isDivisibleBy(101, 25)==false);
    CHECK(isDivisibleBy(34, 11)==false);
}

TEST_CASE("Prime Cases"){
    CHECK(isPrime(2)==true);
    CHECK(isPrime(13)==true);
}

TEST_CASE("Not Prime Cases"){
    CHECK(isPrime(25)==false);
    CHECK(isPrime(4)==false);
    CHECK(isPrime(0)==false);
    CHECK(isPrime(15)==false);
}

TEST_CASE("Next Prime Cases"){
    CHECK(nextPrime(2)==3);
    CHECK(nextPrime(5)==7);
    CHECK(nextPrime(13)==17);
    CHECK(nextPrime(17)==19);
}

TEST_CASE("Correct Prime Count Cases"){
    CHECK(countPrimes(2,7)==4);
    CHECK(countPrimes(4,30)==8);
}

TEST_CASE("Is Twin Prime Cases"){
    CHECK(isTwinPrime(3)==true);
    CHECK(isTwinPrime(5)==true);
    CHECK(isTwinPrime(7)==true);
}

TEST_CASE("Isn't Twin Prime Cases"){
    CHECK(isTwinPrime(23)==false);
    CHECK(isTwinPrime(37)==false);
    CHECK(isTwinPrime(2)==false);
    CHECK(isTwinPrime(15)==false);
}

TEST_CASE("Next Twin Prime Cases"){
    CHECK(nextTwinPrime(3)==5);
    CHECK(nextTwinPrime(37)==41);
    CHECK(nextTwinPrime(17)==19);
}

TEST_CASE("Is Largest Twin Prime"){
    CHECK(largestTwinPrime(5, 18) == 17);
    CHECK(largestTwinPrime(1, 31) == 31);
    CHECK(largestTwinPrime(14, 16) == -1);
}