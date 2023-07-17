#include <iostream>
#include "funcs.h"

int main(){
    std::cout<<"printRange(1,10) : "<<printRange(1,10)<<std::endl;
    std::cout<<"sumRange(1,3) : "<<sumRange(1,3)<<std::endl;

    int size = 10;
    int *arr = new int[size]; // allocate array dynamically
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

    int sum1 = sumArray(arr, size); // Add all elements
    std::cout << "Sum is " << sum1 << std::endl;  // Sum is 43
    delete[] arr;

    std::cout << "isAlphanumeric(\"ABCD\") : "<<isAlphanumeric("ABCD") << std::endl; 
    std::cout << nestedParens("((()))") << std::endl; 
    return 0;
}