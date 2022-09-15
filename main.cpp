#include <iostream>
#include "reservoir.h"
int main(){
    std::string date;
    std::cout << "Enter date: " << std::endl;
    std::cin >> date;
	std:: cout << get_east_storage(date) << std::endl;

    double min_east = get_min_east();
    std::cout << "Minimum storage in East basin: " << min_east << " billion gallons." << std::endl;

    double max_east = get_max_east();
    std::cout << "Maximum storage in East basin: " << max_east << " billion gallons." << std::endl;

    std::cout << "Enter date: " << std::endl;
    std::cin >> date;
    std:: cout << compare_basins(date) << std::endl;
    
    return 0;
}

