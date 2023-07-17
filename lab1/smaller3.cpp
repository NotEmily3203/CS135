// Name: Emily Lin; Github: NotEmily3203

#include <iostream>
int main(){
    int fnum;
    int snum;
    int tnum;
    std::cout<<"Enter the first number: ";
    std::cin>>fnum;
    std::cout<<"Enter the second number: ";
    std::cin>>snum;
    std::cout<<"Enter the third number: ";
    std::cin>>tnum;
    if(fnum == snum && snum == tnum){
        std::cout<<"These numbers are all even"<<std::endl;
    }else if(fnum > snum && snum < tnum){
        std::cout<<"The smallest of the three is: "<<snum<<std::endl;
    }else if(fnum > tnum && tnum < snum){
        std::cout<<"The smallest of the three is: "<<tnum<<std::endl;
    }else if(snum > fnum && fnum < tnum){
        std::cout<<"The smallest of the three is: "<<fnum<<std::endl;
    }
    return 0;
}