#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("printRange function"){
    CHECK(printRange(1,10) == "1 2 3 4 5 6 7 8 9 10 ");
}

TEST_CASE("sumRange function"){
    CHECK(sumRange(1,10) == 55);
    CHECK(sumRange(-2, 10) == 52);
    CHECK(sumRange(1, 3) == 6);
}

TEST_CASE("sumArray function"){
    int size = 10;
    int *arr = new int[size];
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    CHECK(sumArray(arr, size) == 43);
    CHECK(sumArray(arr,5) == 34);
}

TEST_CASE("isAlphanumeric function"){
    CHECK(isAlphanumeric("ABCD") == true);
    CHECK(isAlphanumeric("A-B-C-D") == false);
}

TEST_CASE("nestedParens function"){
    CHECK(nestedParens("(((") == false);
    CHECK(nestedParens(")(") == false);
    CHECK(nestedParens("((()))") == true);
    CHECK(nestedParens("") == true);
}

