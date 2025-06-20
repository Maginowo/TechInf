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
void displayAllEntries(const CarClass *carEntry);
void displaySpecificEntry(const CarClass *carEntry);
void getCarEntry(const CarClass *carEntries);

void addQuickCarEntry(CarClass *carEntry, int maxNumberOfEntries);
void addCarEntry(CarClass *carEntries, int maxNumberOfEntries);
void removeCarEntry(CarClass *carEntries);

void editCarEntry(CarClass *carEntries);

int saveEntriesToFile(const CarClass *carEntries, int maxNumberOfEntries);
int loadEntriesFromFile(CarClass **carEntries, int *maxNumberOfEntries);

int changeMaxNumberOfEntries(CarClass **carEntries, int *maxNumberOfEntries, int newMaxNumberOfEntries, bool override);
#endif //FUNCTIONS_H
