#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>
#include "CarClass.h"

struct carInfo{
    std::string carBrand, carOwner;
    int carValue, carMileage, carYear;
};

void displayMenu();
void displayCarInfo(const CarClass *carEntry);

void addQuickCarEntry(CarClass *carEntry, int maxNumberOfEntries);
void addCarEntry(CarClass *carEntries, int maxNumberOfEntries);
void removeCarEntry(CarClass *carEntries);

void editCarEntry(CarClass *carEntries);



#endif //FUNCTIONS_H
