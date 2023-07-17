//Name: Emily Lin; Github: NotEmily3203

#include <iostream>
int main(){
    int year;
    std::cout<<"Enter year: "<<std::endl;
    std::cin>>year;
    if(year%4 != 0){
        std::cout<<"Common year"<<std::endl;
    }else if(year%100 != 0){
        std::cout<<"Leap year"<<std::endl;
    }else if(year%400 != 0){
        std::cout<<"Common year"<<std::endl;
    }else{
        std::cout<<"Leap year"<<std::endl;
    }
    return 0;
}