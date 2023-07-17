#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"
void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;      
    std::getline(fin, junk);
    std::string date;
    double east_storage;
    double east_elevation;
    double west_storage;
    double west_elevation;
    std::string cont = "false";
    int counter = 0;
    std::string dates[365];
    double data[365];
    while(fin >> date >> east_storage >> east_elevation >> west_storage >> west_elevation){
        fin.ignore(INT_MAX, '\n');
        if(date1 == date){
            cont = "true";
        }else if(date2 == date){
            cont = "once";
        }
        if(cont == "true"){
            dates[counter] = date;
            //std::cout<<dates[counter];
            data[counter] = west_elevation;
            //std::cout<<data[counter];
            counter++;
        }else if(cont == "once"){
            dates[counter] = date;
            data[counter] = west_elevation;
            break;
        }
    }
    for(int i=counter;i>=0;i--){
        std::cout<<dates[i]<<" "<<data[i]<<" ft"<<std::endl;
    }
}