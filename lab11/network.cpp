#include <iostream>
#include "network.h"
#include "social.h"
int Network::findID (std::string usrn){
    int id = -1;
    for(int i = 0; i < MAX_USERS; i++){
        if(usrn == profiles[i].getUsername())
        id = i;
    }
    return id;
}
Network::Network(){
    numUsers = 0;
    for(int i = 0; i<MAX_USERS; i++){
        for(int j = 0; j<MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}
bool Network::addUser(std::string usrn, std::string dspn){
    //the array profiles is not full
    if(numUsers<MAX_USERS){
        //the new username usrn must be a non-empty alphanumeric string
        for(int i = 0; i<usrn.length(); i++){
            if(isalpha(usrn[i]) || isdigit(usrn[i]) || !usrn.empty()){
                //there is no other users in the network with the same username
                if(findID(usrn) == -1){
                    profiles[numUsers] = Profile(usrn, dspn);
                    numUsers++;
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
                break;
            }
        }
    }   
}

bool Network::follow(std::string usrn1, std::string usrn2){
    int id1 = findID(usrn1);
    int id2 = findID(usrn2);
    if(id1 == -1 || id2 == -1 || id1 == id2){
        return false;
    }
    following[id1][id2] = true;
    return true;
}
void Network::printDot(){
    std::cout<<"diagram {\n";
    for(int i = 0; i<numUsers; i++){
        std::cout<<"\"@"<<profiles[i].getUsername()<<"\""<<std::endl;
    }
    for(int j = 0; j<numUsers; j++){
        for(int k = 0; k<numUsers; k++){
            if(following[j][k]){
                std::cout<<"\"@"<<profiles[j].getUsername()<<"\" -> \"@"<<profiles[k].getUsername()<<"\""<<std::endl;
            }
        }
    }
    std::cout<<"}\n";
}