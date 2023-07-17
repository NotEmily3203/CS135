// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;      
    std::getline(fin, junk);
    std::string dates;
    double eastSt;
    while(fin >> dates >> eastSt) { 
        fin.ignore(INT_MAX, '\n'); 
        if(date == dates){
        return eastSt;
        }
    }
    fin.close();
}
double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(fin, junk);
    std::string date;
    double min;
    double temp = 1000;
    while (fin >> date >> min) {
        fin.ignore(INT_MAX, '\n');
        if (min < temp) {
        temp = min;
        }
    }
    return temp;
    fin.close();
}
double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(fin, junk);
    std::string date;
    double max;
    double temp = 0;
    while (fin >> date >> max) {
        fin.ignore(INT_MAX, '\n');
        if (max > temp) {
        temp = max;
        }
    }
    return temp;
    fin.close();
}
std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;      
    std::getline(fin, junk);
    std::string dates;
    double east_storage;
    double east_elevation;
    double west_storage;
    double west_elevation;
    std::string compare;
    while(fin >> dates >> east_storage >> east_elevation >> west_storage >> west_elevation) { 
        fin.ignore(INT_MAX, '\n'); 
        if(date == dates){
            if(east_elevation > west_elevation){
                compare = "East";
            }else if(east_elevation < west_elevation){
                compare = "West";
            }else{
                compare = "Equal";
            }
        }
    }
    return compare;
    fin.close();
}