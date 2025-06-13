#include "Functions.h"
#include "CarClass.h"

using namespace std;

void displayMenu() {
    cout << endl << "======= MENU =======" << endl;
    cout << "1. List" << endl;
    cout << "2. Add entry" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}
void displayCarInfo(const CarClass& carEntry) {
    carEntry.printInfo();
    cout << endl;
}

void addCarEntry(CarClass carEntriesArray[], int maxNumberOfEntries) {
    if (CarClass::numberOfCarEntries() == maxNumberOfEntries) {
        cout << "Max number of entries has been reached. Current max: " << maxNumberOfEntries << ". Trying to allocate more memory..." << endl;
    } else {
        struct carInfo tempCarInfo;

        cout << "Brand name: " << endl;
        cin >> tempCarInfo.carBrand;
        cout << "Car owner: " << endl;
        cin >> tempCarInfo.carOwner;
        cout << "Car value: " << endl;
        cin >> tempCarInfo.carValue;
        cout << "Car mileage: " << endl;
        cin >> tempCarInfo.carMileage;
        cout << "Car year: " << endl;
        cin >> tempCarInfo.carYear;
        carEntriesArray[CarClass::numberOfCarEntries()] = CarClass(tempCarInfo.carBrand, tempCarInfo.carOwner, tempCarInfo.carValue, tempCarInfo.carMileage, tempCarInfo.carYear);
        CarClass::incrementNumberOfCarEntries();
    }
}