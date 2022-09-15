#include<iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date){ 
    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl; //c outs errors
        exit(1); // exit if failed to open the file
    }
    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file; got the first row and left it alone

    //initialize variables 
    std::string fileDate;
    double eastSt, eastEl, westSt, westEl;

    while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); //ignores rest of the field names 
        if (date == fileDate ){
            std::cout << "East basin storage: " << eastSt << " billion gallons." << std::endl;
        }
    }
    return 0;
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
    std::cout << "Minimum storage in East basin: " << min << " billion gallons." << std::endl;
    fin.close();
    return 0;
} 

double get_max_east(){ //this function should return the maximum storage in the East basin in the 2018.
    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl; //c outs errors
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
    std::cout << "Maximum storage in East basin: " << max << " billion gallons." << std::endl;
    fin.close(); 
    return 0;
}

// std::string compare_basins(std::string date){

//     return 0;
// }

