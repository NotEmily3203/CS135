/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 3 A
This is the profemon class
*/

#include <iostream>
#include "profemon.hpp"

Profemon::Profemon(){
    pname = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    pname = name;
    pmax_health = max_health;
    pspecialty = specialty;
    preq_exp = 50;
    pcurr_exp = 0;
    plevel = 0;
}

std::string Profemon::getName(){
    return pname;
}

Specialty Profemon::getSpecialty(){
    return pspecialty;
}

int Profemon::getLevel(){
    return plevel;
}

double Profemon::getMaxHealth(){
    return pmax_health;
}

void Profemon::setName(std::string name){
    pname = name;
}

void Profemon::levelUp(int exp){
    pcurr_exp += exp;
    do {
        if(pcurr_exp >= preq_exp){
            plevel ++;
            pcurr_exp -= preq_exp;
            switch (pspecialty)
            {
            case ML:
                preq_exp += 10;
                break;
            case SOFTWARE:
                preq_exp += 15;
                break;
            case HARDWARE:
                preq_exp += 20;
                break;
            default:
                break;
            }
        }
    } while(pcurr_exp >= preq_exp);
}

bool Profemon::learnSkill(int slot, Skill skill){
    if (slot > 2 or slot < 0 or skill.getSpecialty() != pspecialty){
        return false;
    } else {
        set[slot] = skill;
        return true;
    }
}

void Profemon::printProfemon(bool print_skills){
    std::string special;
    switch(getSpecialty()){
        case 0:
            special = "ML";
            break;
        case 1:
            special = "SOFTWARE";
            break;
        case 2:
            special = "HARDWARE";
            break;
        default:
            special = "UNDEFINED";
            break;
    }
    std::cout<<pname<<" ["<<special<<"] | lvl "<<plevel<<" | exp "<<pcurr_exp<<"/"<<preq_exp<<" | hp "<<pmax_health<<std::endl;
    if(print_skills){
        for(int i = 0; i<3; i++){
            if(set[i].getName() != "Undefined"){
                std::cout<<"    "<<set[i].getName()<<" ["<<set[i].getTotalUses()<<"] : "<<set[i].getDescription()<<std::endl;
            }
        }
    }
}