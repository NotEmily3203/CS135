#include <iostream>
#include "funcs.h"

// add functions here
bool isDivisibleBy(int n, int d){
    bool divisible = false;
    if(n%d == 0){
        divisible = true;
    }
    return divisible;
}

bool isPrime(int n){
    bool prime = true;
    for(int i=2;i<n-1;i++){
        if(isDivisibleBy(n, i)){
            prime = false;
            break;
        }
    }
    if(n==0 || abs(n)==1){
        prime = false;
    }
    return prime;
}

int nextPrime(int n){
    int prime = n+1;
    while(isPrime(prime)==false){
        prime++;
    }
    return prime;
}

int countPrimes(int a, int b){
    int tempPrime = a;
    int count = 0;
    for(int i = a; i <= b; i++){
        if(isPrime(tempPrime)==true){
            count++;
        }
        tempPrime++;
    }
    return count;
}

bool isTwinPrime(int n){
    bool twin = false;
    if(isPrime(n)==true){
        if(isPrime(n-2)==true || isPrime(n+2)==true){
            twin = true;
        }
    }
    return twin;
}

int nextTwinPrime(int n){
    int twin = n+1;
    while(isPrime(twin)==false){
        twin++;
    }
    while(isTwinPrime(twin)==false){
        twin = nextPrime(n);
    }
    return twin;
}

int largestTwinPrime(int a, int b){
    int largest = -1;
    for(int i=a;i<=b;i++){
        if(isTwinPrime(i)==true){
            largest = i;
        }
    }
    return largest;
}