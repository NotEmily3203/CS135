#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
// add your tests here
TEST_CASE("Correct Caesar Cases"){
    CHECK(encryptCaesar("Hello, World!", 10)== "Rovvy, Gybvn!");
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
}

TEST_CASE("Correct Vigenere Cases"){
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("A@B#C$D%", "cake") == "C@B#M$H%");
}

TEST_CASE("Correct Decryption Cases"){
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("C@B#M$H%", "cake") == "A@B#C$D%");
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
}

TEST_CASE("Correct Frequency Cases"){
    CHECK(frequency('a',"aaaabbddde")==40);
    CHECK(frequency('a',"anaconda")==37.5);
}

TEST_CASE("Correct Distance"){
    double a[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double b[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    CHECK(distance(a,b) == 0);
}

TEST_CASE("Solve using probability"){
    CHECK(solve(encryptCaesar("I loathe bread. Bread is bready so I hate it", 17))=="I loathe bread. Bread is bready so I hate it");
    CHECK(solve(encryptCaesar("Cats are so awesome and adorable and weird!", 6))=="Cats are so awesome and adorable and weird!");
}