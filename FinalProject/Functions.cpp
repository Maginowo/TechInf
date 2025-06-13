#include "Functions.h"
#include "CarClass.h"

using namespace std;

void displayMenu() {
    cout << endl << "======= MENU =======" << endl;
    cout << "1. List" << endl;
    cout << "2. Add quick entry" << endl;
    cout << "3. Add full entry" << endl;
    cout << "4. Remove entry" << endl;
    cout << "5. Editing entry" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}
void displayCarInfo(const CarClass* carEntry) {
    for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
        cout << "ENTRY " << i + 1 << endl;
        carEntry[i].printInfo();
        cout << endl;
    }
}

void addQuickCarEntry(CarClass *carEntries, const int maxNumberOfEntries) {
    if (CarClass::numberOfCarEntries() == maxNumberOfEntries) {
        cout << "Max number of entries has been reached. Current max: " << maxNumberOfEntries << endl;
    } else {
        struct carInfo tempCarInfo;

        cout << "Brand name: " << endl;
        cin >> tempCarInfo.carBrand;
        cout << "Car owner: " << endl;
        cin >> tempCarInfo.carOwner;
        new (&carEntries[CarClass::numberOfCarEntries()]) CarClass(tempCarInfo.carBrand, tempCarInfo.carOwner, 0, 0, 0);

        CarClass::incrementNumberOfCarEntries();
    }
}

void addCarEntry(CarClass *carEntries, const int maxNumberOfEntries) {
    if (CarClass::numberOfCarEntries() == maxNumberOfEntries) {
        cout << "Max number of entries has been reached. Current max: " << maxNumberOfEntries << endl;
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
        new (&carEntries[CarClass::numberOfCarEntries()]) CarClass(tempCarInfo.carBrand, tempCarInfo.carOwner, tempCarInfo.carValue, tempCarInfo.carMileage, tempCarInfo.carYear);

        CarClass::incrementNumberOfCarEntries();
    }
}

void removeCarEntry(CarClass *carEntries) {
    if (CarClass::numberOfCarEntries() == 0) {
        cout << "There are no entries" << endl;
    } else if (CarClass::numberOfCarEntries() == 1) {
        cout << "Only one entry exists. Removing." << endl;
        carEntries[0].~CarClass();
    } else {
        int removingIndex = 0;
        // Showing possible input range
        cout << "Select entry from 1 to " << CarClass::numberOfCarEntries() << endl;

        // Asking user for index in range
        while (removingIndex < 1 || removingIndex > CarClass::numberOfCarEntries()) {
            cout << "Enter entry index: " << endl;
            cin >> removingIndex;
        }

        carEntries[removingIndex - 1].~CarClass(); // destroying

        // Shifting the entries for efficient memory usage
        for (int i = removingIndex - 1; i < CarClass::numberOfCarEntries() - 1; ++i) {
            new (&carEntries[i]) CarClass(carEntries[i + 1]);
            carEntries[i + 1].~CarClass();
        }
        CarClass::decrementNumberOfCarEntries();

        cout << "Entry " << removingIndex << " has been removed." << endl;
    }
}

void editCarEntry(CarClass *carEntries) {
    int editingIndex = 0, selection = 0;
    string input;
    // Showing possible input range
    cout << "Select entry from 1 to " << CarClass::numberOfCarEntries() << endl;

    // Asking user for index in range
    while (editingIndex < 1 || editingIndex > CarClass::numberOfCarEntries()) {
        cout << "Enter entry index: " << endl;
        cin >> editingIndex;
    }
    editingIndex--;
    cout << endl << "What would you like to edit?" << endl;
    cout << "1. Brand" << endl;
    cout << "2. Owner" << endl;
    cout << "3. Value" << endl;
    cout << "4. Mileage" << endl;
    cout << "5. Year" << endl;
    cout << "0. Nothing" << endl;
    cin >> selection;
    cin >> input;
    switch (selection) {
        case 1:
            carEntries[editingIndex].setBrand(input);
            break;
        case 2:
            carEntries[editingIndex].setOwnerName(input);
            break;
        case 3:
            carEntries[editingIndex].setValue(stod(input));
            break;
        case 4:
            carEntries[editingIndex].setMileage(stod(input));
            break;
        case 5:
            carEntries[editingIndex].setYear(stoi(input));
            break;
        default:
            cout << "Invalid selection. Aborting." << endl;
    }
}