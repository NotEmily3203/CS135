/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 3 A
This is the skill class
*/

#include <iostream>
#include "skill.hpp"
Skill::Skill(){
    sname = "Undefined";
    sdescription = "Undefined";
    suses = -1;
    sspecialty = -1;
}

Skill::Skill(std::string name, std::string description, int specialty, int uses){
    sname = name;
    sdescription = description;
    sspecialty = specialty;
    suses = uses;
}

std::string Skill::getName(){
    return sname;
}

std::string Skill::getDescription(){
    return sdescription;
}

int Skill::getTotalUses(){
    return suses;
}

int Skill::getSpecialty(){
    return sspecialty;
}

void Skill::setName(std::string name){
    sname = name;
}

void Skill::setDescription(std::string description){
    sdescription = description;
}

void Skill::setTotalUses(int uses){
    suses = uses;
}

bool Skill::setSpecialty(int specialty){
    if(specialty >= 0 && specialty <= 2){
        sspecialty = specialty;
        return true;
    }else{
        return false;
    }
}