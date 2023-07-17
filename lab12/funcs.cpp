#include "funcs.h"
#include <iostream>
#include <vector>

std::vector<int> makeVector(int n){
    std::vector<int> result;
    for(int i = 0; i < n; i++){
        result.push_back(i);
    }
    return result;
}

std::vector<int> goodVibes(const std::vector<int>& v){
    std::vector<int> result;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0){
            result.push_back(v[i]);
        }
    }
    return result;
}

void gogeta(std::vector<int> &goku, std::vector<int> &vegeta){
    for(int i = 0; i < vegeta.size(); i++){
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}

std::vector<int> sumPairWise(const std::vector<int> &v1, const std::vector<int> &v2){
    std::vector<int> result;
    int size;
    if(v1.size() >= v2.size()){
        size = v1.size();
    }else{
        size = v2.size();
    }
    for(int i = 0; i<size; i++){
        result.push_back(v1[i] + v2[i]);
    }
    return result;
}