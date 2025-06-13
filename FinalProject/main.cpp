#include <iostream>
#include "CarClass.h"
#include "Functions.h"

using namespace std;

int main() {
    int option = 0;
    int maxNumberOfEntries = 3;

    CarClass *carEntriesArray;

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

                for (int i = 0; i < CarClass::numberOfCarEntries(); i++) {
                    displayCarInfo(carEntriesArray[i]);
                }
                break;

            case 2:
                addCarEntry(carEntriesArray, maxNumberOfEntries);
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}
