#include <iostream>
#define SIZE 9
#include "arrayOperations.h"


void menu(){
    printf("\n\n\t---MENU---\n");
    printf("0 - End Program\n");
    printf("1 - Print Elements\n");
    printf("2 - Set All Elements\n");
    printf("3 - Set Selected Element\n");
    printf("4 - Find Minimum Value\n");
    printf("5 - Find Maximum Value\n");
    printf("6 - Calculate Average Value\n");
    printf("7 - Calculate Median Value\n");
    printf("8 - Sort The Array\n");
    printf("9 - Preview The Array As Sorted Without Making Changes\n");
    printf("10 - Save The Array To File\n");
    printf("11 - Load Array From File\n");
    printf("Select the option: \n");
}


int main() {
    int numbers[SIZE] = {9, 14, 11, 5, 8, 15, 4, 3, 7};
    const int *ptrNumbers = numbers; // Pointer with NOT editable values
    int *ptrEditNumbers = numbers; // Pointer with editable values
    int option = 0; // Stores selected option by user
    int errorCode;

    do{
        menu();
        scanf("%d", &option);
        printf("\n"); // Gives space from the menu

        switch(option) {
            case (0):
                break;

            case (1):
                printElements(ptrNumbers, SIZE);
                break;

            case (2):
                setAllElements(ptrEditNumbers, SIZE);
                break;

            case (3):
                setTheElement(ptrEditNumbers, SIZE);
                break;

            case (4):
                printf("\nMinimum value is: %d\n", findMinimumValue(ptrNumbers, SIZE));
                break;

            case (5):
                printf("Maximum value is: %d\n", findMaximumValue(ptrNumbers, SIZE));
                break;

            case (6):
                printf("Average value is: %.2lf\n", calculateAverageValue(ptrNumbers, SIZE));
                break;

            case (7):
                printf("Median value is: %.2lf\n", calculateMedianValue(ptrEditNumbers, SIZE));
                break;

            case (8):
                printf("\nSorting...\n");
                sortArray(ptrEditNumbers, SIZE);
                printf("Array sorted.\n");
                break;

            case (9):
                previewArrayAsSorted(ptrNumbers, SIZE);
                break;

            case (10):
                errorCode = saveArrayToFile(ptrNumbers, SIZE);
                if(!errorCode){ printf("Array saved to file successfully.\n"); }
                else{ printf("Something went wrong...\n"); }

                break;

            case (11):
                errorCode = restoreArrayFromFile(ptrEditNumbers, SIZE);
                if(!errorCode){ printf("Array loaded successfully.\n"); }
                else{ printf("Something went wrong...\n"); }

                break;

            default:
                printf("Please select viable option.\n");
        }
    } while ( option!=0 );

    printf("Goodbye!\n");

    return 0;
}