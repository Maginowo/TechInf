#include <iostream>
#include "CarClass.h"
#include "Functions.h"

using namespace std;

int main() {
    int option = 0;
    int maxNumberOfEntries = 3;

    CarClass *carEntries = (CarClass *)malloc(sizeof(CarClass) * maxNumberOfEntries);

    while (true){
        displayMenu();
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                if (CarClass::numberOfCarEntries() == 0) {
                    cout << "There are no car entries" << endl;
                    break;
                }
                displayCarInfo(carEntries);
                break;

            case 2:
                addQuickCarEntry(carEntries, maxNumberOfEntries);
                break;

            case 3:
                addCarEntry(carEntries, maxNumberOfEntries);
                break;

            case 4:
                removeCarEntry(carEntries);
                break;

            case 5:
                editCarEntry(carEntries);
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
