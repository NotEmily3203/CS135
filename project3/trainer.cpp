#include <iostream>
#include <vector>
#include "trainer.hpp"

Trainer::Trainer(){
    current = nullptr;
}

Trainer::Trainer(std::vector <Profemon> profemons){
    //int i = 0;
    for(int i = 0; i<profemons.size(); i++){
        if(i < 3 && team[i].getName() == "Undefined"){
            team[i] = profemons[i];
        }else{
            profedex.push_back(profemons[i]);
        }
    }
    current = &team[0];
}//

bool Trainer::contains(std::string name){
    for(int i = 0; i<3; i++){
        if(team[i].getName() == name){
            return true;
        }
    }
    for(int j = 0; j<profedex.size(); j++){
        if(profedex[j].getName() == name){
            return true;
        }
    }
    return false;
}//

bool Trainer::addProfemon(Profemon profemon){
    int i = 0;
    if(contains(profemon.getName())){
        return false;
    }
    while(i<3){
        if(team[i].getName() == "Undefined"){
            team[i] = profemon;
            return true;
        }
        i++;
    }
    profedex.push_back(profemon);
    return true;
}//

bool Trainer::removeProfemon(std::string name){
    std::vector <Profemon> ordered;
    Profemon empty;
    int i = 0;
    bool remove = false;
    for(int i = 0; i<profedex.size(); i++){
        if(name == profedex[i].getName()){
            remove = true;
        }else{ // makes ordered vector without removed
            ordered.push_back(profedex[i]);
        }
    }
    if(remove){
        profedex = ordered;
        return true;
    }
    while(i<3){
        if(team[i].getName() == name){
            team[i] = empty;
            return true;
        }
        i++;
    }
    return false;
}

void Trainer::setTeamMember(int slot, std::string name){
    Profemon temp;
    for(int i = 0; i<profedex.size(); i++){
        if(profedex[i].getName() == name){
            if(team[slot].getName() == "Undefined"){
                team[slot] = profedex[i];
                removeProfemon(name);
            }else{
                temp = profedex[i];
                profedex[i] = team[slot];
                team[slot] = temp;
            }
        }
    }
}

bool Trainer::chooseProfemon(int slot){
    if(team[slot].getName() == "Undefined"){
        return false;
    }else{
        current = &team[slot];
        return true;
    }
}

Profemon Trainer::getCurrent(){
    return *current;
}

void Trainer::printProfedex(){
    for (int i = 0; i<profedex.size(); i++){
        profedex[i].printProfemon(false);
        std::cout << std::endl;
    }
}

void Trainer::printTeam(){
    for (int i = 0; i<3; i++){
        if(team[i].getName() != "Undefined"){
            team[i].printProfemon(true);
            std::cout << std::endl;
        }
    }
}