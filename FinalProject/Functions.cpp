#include "Functions.h"
#include "CarClass.h"

using namespace std;

void displayMenu() {
    cout << endl << "======= MENU =======" << endl;
    cout << "1. List all entries" << endl;
    cout << "2. List specific entry" << endl;
    cout << "3. Add quick entry" << endl;
    cout << "4. Add full entry" << endl;
    cout << "5. Remove entry" << endl;
    cout << "6. Editing entry" << endl;
    cout << "7. Search for entry with highest/lowest value" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}
void displayAllEntries(const CarClass* carEntry) {
    for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
        cout << "ENTRY " << i + 1 << endl;
        carEntry[i].printInfo();
        cout << endl;
    }
}
void displaySpecificEntry(const CarClass *carEntry) {
    int entryIndex = 0;
    // Showing possible input range
    cout << "Select entry from 1 to " << CarClass::numberOfCarEntries() << endl;

    // Asking user for index in range
    while (entryIndex < 1 || entryIndex > CarClass::numberOfCarEntries()) {
        cout << "Enter entry index: " << endl;
        cin >> entryIndex;
    }
    carEntry[entryIndex - 1].printInfo();
}
void getCarEntry(const CarClass *carEntries) {
    int selection = 0, search = 0; // User input ints
    double resultValue = 0;
    int resultIndex = 0;

    // Get search category input from user
    cout << "Search for" << endl << "1. Highest" << endl << "2. Lowest" << endl;
    while (search < 1 || search > 2) {
        cin >> search;
    }

    // Get which value we will be searching for to be highest/lowest
    cout << "Possible values to search for:" << endl;
    cout << "1. Value" << endl;
    cout << "2. Mileage" << endl;
    cout << "3. Year" << endl;
    while (selection < 1 || selection > 3) {
        cin >> selection;
    }

    // Confirm what we are searching for and search for it
    cout << "We are searching for the ";
    (search == 1) ? cout << "highest " : cout << "lowest ";
    cout << "value of ";
    switch (selection) {
        case 1:
            cout << "value." << endl;

            resultValue = carEntries[0].getValue();
            if (search == 1) {
                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    if (carEntries[i].getValue() > resultValue) { resultValue = carEntries[i].getValue(); resultIndex = i; } // If current entry value is higher than that in the resultValue, set it to it
                }
            } else {
                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    if (carEntries[i].getValue() < resultValue) { resultValue = carEntries[i].getValue(); resultIndex = i; } // If current entry value is lower than that in the resultValue, set it to it
                }
            }

            break;

        case 2:
            cout << "mileage." << endl;

            resultValue = carEntries[0].getMileage();
            if (search == 1) {
                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    if (carEntries[i].getMileage() > resultValue) { resultValue = carEntries[i].getMileage(); resultIndex = i; } // If current entry value is higher than that in the resultValue, set it to it
                }
            } else {
                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    if (carEntries[i].getMileage() < resultValue) { resultValue = carEntries[i].getMileage(); resultIndex = i; } // If current entry value is lower than that in the resultValue, set it to it
                }
            }

            break;

        case 3:
            cout << "year." << endl;

            resultValue = carEntries[0].getYear();
            if (search == 1) {
                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    if (carEntries[i].getYear() > resultValue) { resultValue = carEntries[i].getYear(); resultIndex = i; } // If current entry value is higher than that in the resultValue, set it to it
                }
            } else {
                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    if (carEntries[i].getYear() < resultValue) { resultValue = carEntries[i].getYear(); resultIndex = i; } // If current entry value is lower than that in the resultValue, set it to it
                }
            }

            break;
    }
    cout << "The result is: " << resultValue << " in entry " << resultIndex + 1 << "." << endl;
    carEntries[resultIndex].printInfo();
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