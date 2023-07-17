/*
Author: Emily Lin
Course: CSCI 13500
Instructor: Genadiy Maryash
Assignment: Project 3 A
This is the department class
*/
#include <iostream>
#include <string>
#include <vector>
#include "department.hpp"

MLDepartment::MLDepartment(std::vector<Profemon> profemons){
    for(int i = 0; i<profemons.size(); i++){
        if(profemons[i].getSpecialty() == 0){
            MLDepartment::addProfemon(profemons[i]);
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 0){
        Trainer::addProfemon(profemon);
        return true;
    }else{
        return false;
    }
}


SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].getSpecialty() == 1){
            SoftwareDepartment::addProfemon(profemons[i]);
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 1){
        Trainer::addProfemon(profemon);
        return true;
    }else{
        return false;
    }
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].getSpecialty() == 2){
            HardwareDepartment::addProfemon(profemons[i]);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == 2){
        Trainer::addProfemon(profemon);
        return true;
    }else{
        return false;
    }
}