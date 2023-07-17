// Name: Emily Lin; Github: NotEmily3203

#include <iostream>

int main(){
    int fnum;
    int snum;
    std::cout<<"Enter the first number: ";
    std::cin>>fnum;
    std::cout<<"Enter the second number: ";
    std::cin>>snum;
    if(fnum>snum){
        std::cout<<"The smaller of the two is "<<snum<<std::endl;
    }else if(fnum==snum){
        std::cout<<"These numbers are equal"<<std::endl;
    }else{
        std::cout<<"The smaller of the two is "<<fnum<<std::endl;
    }
}