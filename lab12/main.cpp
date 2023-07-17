#include "funcs.h"
#include <iostream>
#include <vector>

int main(){
    std::vector<int> e1 = makeVector(5);
    std::cout<<"makeVector(5) : ";
    for(int i = 0; i<5; i++){
        std::cout<<e1[i]<<" ";
    } 
    std::cout<<std::endl;

    const std::vector<int> v {-2,-1,0,1,-5,2,3};
    std::vector<int> e2 = goodVibes(v);
    std::cout<<"goodVibes(v) : ";
    for(int j = 0; j<e2.size(); j++){
        std::cout<<e2[j]<<" ";
    }
    std::cout<<std::endl;

    std::vector<int> v1{1,2,3};
    std::vector<int> v2{4,5};
    gogeta(v1, v2);
    std::cout<<"gogeta(v1, v2) : \nv1 : ";
    for(int k = 0; k < v1.size(); k++){
        std::cout<<v1[k]<<" ";
    }
    std::cout<<"\nv2 : ";
    for(int l = 0; l < v2.size(); l++){
        std::cout<<v1[l]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"sumPairWise(t1, t2) : ";
    std::vector<int> t1{1,2,3};
    std::vector<int> t2{4,5};
    std::vector<int> result = sumPairWise(t1, t2); // returns [5, 7, 3]
    for(int m = 0; m < result.size(); m++){
        std::cout<<result[m]<<" ";
    }
    std::cout<<std::endl;
}