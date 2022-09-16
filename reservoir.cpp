#include<iostream>
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
    getline(fin, junk); 

    //initialize variables 
    std::string fileDate;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if (date == fileDate ){
            return eastSt;
        }
    }
    return eastSt;
    fin.close();
}

double get_min_east(){ //this function should return the minimum storage in the East basin in the 2018.
    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); 
    }
    std::string junk;     
    getline(fin, junk); 

    std::string fileDate;
    double eastSt, eastEl, westSt, westEl;

    double min = INT_MAX;
    while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if (eastSt < min){
            min = eastSt;
        }
    }
    fin.close();
    return min;
} 

double get_max_east(){ //this function should return the maximum storage in the East basin in the 2018.
    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl; 
        exit(1); 
    }
    std::string junk;        
    getline(fin, junk); 

    std::string fileDate;
    double eastSt, eastEl, westSt, westEl;

    double max = INT_MIN;
    while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if (eastSt > max){
            max = eastSt;
        }
    }
    fin.close(); 
    return max;
}

std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl; 
        exit(1); 
    }

    std::string junk;        
    getline(fin, junk); 

    std::string fileDate;
    double eastSt, eastEl, westSt, westEl;

    std::cout << "Enter a date: " << std::endl;

    while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if (date == fileDate){
            if (eastSt > westSt){
            return "East";
            }
        else if (westSt > eastSt) {
            return "West";
            }
        else {
            return "Equal";
            }  
        }
    }
    fin.close(); 
    return "";
}

