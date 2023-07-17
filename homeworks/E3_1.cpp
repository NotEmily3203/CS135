//This program determines whether an int is +/-/0
#include <iostream>
int main(){
    int x;
    std::cout<<"Enter an integer: ";
    std::cin>>x;
    if(x==0){
        std::cout<<"Zero"<<std::endl;
    }else if(x>0){
        std::cout<<"Positive"<<std::endl;
    }else{
        std::cout<<"Negative"<<std::endl;
    }
    return 0;
}