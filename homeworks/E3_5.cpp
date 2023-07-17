//This program determines whether an array of numbers is increasing, decreasing, or neither
#include <iostream>
int main(){
    int nums[3];
    for(int i=0;i<3;i++){
        std::cout<<"Enter a number: ";
        std::cin>>nums[i];
    }
    if(nums[0]<nums[1] && nums[1]<nums[2]){
        std::cout<<"Increasing";
    }else if(nums[0]>nums[1] && nums[1]>nums[2]){
        std::cout<<"Decreasing";
    }else{
        std::cout<<"Neither";
    }
    return 0;
}