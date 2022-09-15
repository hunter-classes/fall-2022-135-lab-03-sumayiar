#include <iostream>
#include "reservoir.h"
int main(){
    std::string date;
    std::cout << "Enter date: " << std::endl;
    std::cin >> date;
	get_east_storage(date);
    get_min_east();
    get_max_east();
return 0;
}

