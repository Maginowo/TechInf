#include <iostream>
#include "CarClass.h"
#include "Functions.h"

using namespace std;

int main() {
    int option = 0, errorCode = 0;
    int maxNumberOfEntries = 3;

    CarClass *carEntries = (CarClass *)malloc(sizeof(CarClass) * maxNumberOfEntries);

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
                errorCode = loadEntriesFromFile(carEntries, &maxNumberOfEntries);
                if(!errorCode){ printf("Entries loaded successfully.\n"); }
                else{ printf("Something went wrong...\n"); }

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
