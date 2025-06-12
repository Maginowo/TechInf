#include <iostream>
#include "CarClass.h"


void menu() {
    std::cout << std::endl << "======= MENU =======" << std::endl;
    std::cout << "1. Info" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    int option = 0;

    CarClass carArray[10];
    carArray[1] = CarClass("VW", "John Johnald", 30000, 500, 2012);

    while (true){
        menu();
        std::cin >> option;

        switch (option) {
            case 1:
                carArray[1].printInfo();
                break;

            case 2:
                return 0;

            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    }
    return 0;
}
