#include <iostream>
#include "list.h"

void clear(void) {
    while (getchar() != '\n');
}

void menu(void){
    printf("STACK AND QUEUE using lists and structures\n");
    printf("11/12 - Add an element to the stack (on top)/queue (on bottom)\n");
    printf("21/22 - Read an element from the stack (from top)/queue (from bottom)\n");
    printf("31/32 - Delete an element from the stack (from top)/queue (from bottom)\n");
    printf("6 - Print the list of the stack/queue\n");
    printf("7 - End program\n\n");
}

int main() {
    int value = 0, index = 0, option = 0, errorCode = 0;

    while (1) {
        menu();
        while (!scanf("%d", &option)) {
            printf("Not an integer! Input an integer: ");
            clear();
        }

        switch (option) {
            case 11: // add at the top (stack)
                printf("Input a number to be added: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = insertBack(value);
                !errorCode ? printf("Added successfully!\n\n") : printf("Failed to add.\n\n");
                break;

            case 21: // Read from the top (stack)
                printf("Top value is: %d\n", readFromTop());
                break;

            case 31: // Read and delete item from the top (stack)
                printf("Top value is: %d\n", readFromTop());
                errorCode = deleteBack();
                !errorCode ? printf("Top element deleted successfully!\n\n") : printf(
                        "Failed to delete the last element.\n\n");
                break;

            case 12: // add at the front (queue)
                printf("Input a number: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = insertFront(value);
                !errorCode ? printf("Added successfully!\n\n") : printf("Failed to add.\n\n");
                break;

            case 22: // read from the beginning (queue)
                printf("Bottom value is: %d\n", readFromBeginning());
                break;

            case 32: // Read and delete the value at the beginning (queue)
                printf("Bottom value is: %d\n", readFromBeginning());
                errorCode = deleteFront();
                !errorCode ? printf("Bottom element deleted successfully!\n\n") : printf(
                        "Failed to delete the last element.\n\n");
                break;

            case 6:
                printf("List: ");
                printList();
                printf("\n%d elements\n\n", getNodesCount());
                break;

            case 0:
                freeList();
                return 0;

            default:
                //system("cls");
                printf("Wybierz wlasciwa opcje.\n\n");
                break;
        }
    }
}