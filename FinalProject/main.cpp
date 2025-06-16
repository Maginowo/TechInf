#include <iostream>
#include "CarClass.h"
#include "Functions.h"

using namespace std;

int main() {
    int option = 0, errorCode = 0, choiceValue = 0;
    int maxNumberOfEntries = 1; // default value for initialization
    CarClass *carEntries = (CarClass *)malloc(sizeof(CarClass) * maxNumberOfEntries); // Initializng the carEntries

    cout << "1. Load entries from the file" << endl;
    cout << "2. Initialize new database" << endl;
    while (option != 1 && option != 2) { cin >> option; }

    if (option == 1) { // Loading data from file
        errorCode = loadEntriesFromFile(&carEntries, &maxNumberOfEntries);
        if(!errorCode){ printf("Entries loaded successfully.\n"); }
        else {
            printf("Something went wrong... Creating new database.\n");
            option = 2;
        }
    } else if (option == 2) { // Creating new carEntries with set size
        cout << "Please enter the number of entries in the database file. Must be more than 1." << endl;
        while (maxNumberOfEntries < 2) {
            cin >> maxNumberOfEntries;
            CarClass *tempEntries = (CarClass*) realloc(carEntries, (maxNumberOfEntries) * sizeof(CarClass));
            carEntries = tempEntries;
        }
    }

    while (true){
        displayMenu();
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                if (CarClass::numberOfCarEntries() == 0) {
                    cout << "There are no car entries." << endl;
                    break;
                }
                displayAllEntries(carEntries);
                break;

            case 2:
                if (CarClass::numberOfCarEntries() == 0) {
                    cout << "There are no car entries." << endl;
                    break;
                }
                displaySpecificEntry(carEntries);
                break;

            case 3:
                addQuickCarEntry(carEntries, maxNumberOfEntries);
                break;

            case 4:
                addCarEntry(carEntries, maxNumberOfEntries);
                break;

            case 5:
                removeCarEntry(carEntries);
                break;

            case 6:
                editCarEntry(carEntries);
                break;

            case 7:
                if (CarClass::numberOfCarEntries() == 0) {
                    cout << "There are no car entries." << endl;
                    break;
                } else if (CarClass::numberOfCarEntries() == 1) {
                    cout << "There is only one entry, nothing to search for." << endl;
                    break;
                }
                getCarEntry(carEntries);
                break;

            case 8:
                errorCode = saveEntriesToFile(carEntries, maxNumberOfEntries);
                if(!errorCode){ printf("Entries saved to file successfully.\n"); }
                else{ printf("Something went wrong...\n"); }
                break;

            case 9:
                errorCode = loadEntriesFromFile(&carEntries, &maxNumberOfEntries);
                if(!errorCode){ printf("Entries loaded successfully.\n"); }
                else{ printf("Something went wrong...\n"); }

                break;

            case 10:
                cout << "Current number of entries is: " << maxNumberOfEntries << " How many entries do you want to have? Must be at least 1." << endl;
                choiceValue = 0;
                while (choiceValue <= 1) {
                    cin >> choiceValue;
                }
                errorCode = changeMaxNumberOfEntries(&carEntries, &maxNumberOfEntries, choiceValue, false);
                switch (errorCode) {
                    case 1:
                        cout << "Reallocation failed." << endl;
                        break;
                    case 2:
                        cout << "Aborting shrinking. Nothing changed" << endl;
                        break;
                    default:
                        // It worked
                        break;
                }
                break;

            case 0:
                free(carEntries);
                return 0;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}
