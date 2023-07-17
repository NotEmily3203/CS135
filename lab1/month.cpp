// Name: Emily Lin; Github: NotEmily3203

#include <iostream>
int main(){
    int year;
    bool leap;
    int month;
    std::cout<<"Enter year: "<<std::endl;
    std::cin>>year;
    if(year%4 != 0){
        leap = false;
    }else if(year%100 != 0){
        leap = true;
    }else if(year%400 != 0){
        leap = false;
    }else{
        leap = true;
    }
    std::cout<<"Enter month number: ";
    std::cin>>month;
    bool more_days = false;
    if(month >= 8 && month <=12){
        if(month%2 == 0){
            more_days = true;
        }
    }else{
        if(month%2 != 0){
            more_days = true;
        }
    }
    if(leap == true){
        if(month == 2){
            std::cout<<"29 days";
        }else{
            if(more_days == true){
                std::cout<<"31 days";
            }else{
                std::cout<<"30 days";
            }
        }
    }else{
        if(month == 2){
            std::cout<<"28 days";
        }else{
            if(more_days == true){
                std::cout<<"31 days";
            }else{
                std::cout<<"30 days";
            }
        }
    }
    return 0;
}