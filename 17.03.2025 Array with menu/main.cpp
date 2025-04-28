#include <iostream>
#define SIZE 9

void printElements(const int *ptrArray, const int size){
    printf("Array Contents:\n");
    for(int i = 0;i<size;i++){
        printf("%d, ", *(ptrArray + i));
    }
    printf("\n");
}

void setAllElements(int *array, const int size){
    printf("Write numbers into the array: ");
    for(int i = 0;i<SIZE;i++){
        //std::cin >> array[i];
        scanf("%d", array + i);
    }
}

void setTheElement(int *array, const int size){
    int index = 0;
    int newValue = 0;
    printf("Choose element to edit in range of 0 to %d\n", size - 1);
    scanf("%d", &index);
    printf("Element %d has the value of %d. Write the new value: ", index, *(array + index));
    scanf("%d", &newValue);

    *(array + index) =  newValue;

    printf("The change has been done.\n");
}

int findMaximumValue(const int *array, const int size){
    int maxValue = *(array);
    for(int i = 0; i < size; i++){
        if(maxValue<*(array + i)){ maxValue = *(array + i); }
    }
    return maxValue;
}

int findMinimumValue(const int *array, const int size){
    int minValue = *(array);
    for(int i = 0; i < size; i++){
        if(minValue>*(array + i)){ minValue = *(array + i); }
    }
    return minValue;
}

double calculateAverageValue(const int array[], const int size){
    double arraySum = 0;
    for(int i = 0; i < size; i++){
        arraySum += *(array + i);
    }
    return arraySum/size;
}

void sortArray(int *array, const int size){
    // Sorting the array with bubble sort
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size - 1; j++){
            // Changing the elements if the next one is smaller
            if(array[j]>*(array + j + 1)){
                int swappedValue = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = swappedValue;
            }
        }
    }
}


void copyArray(const int *originalArray, int *newArray, const int size){
    for(int i = 0; i<size; i++){
        *(newArray + i) = *(originalArray + i);
    }
}

void previewArrayAsSorted(const int *array, const int size){
    int tempArray[size];
    copyArray(array, tempArray, size);
    sortArray(tempArray, size);
    printElements(tempArray, size);
}

double calculateMedianValue(const int *array, const int size){
    int tempArray[size];
    copyArray(array, tempArray, size); // creating the temporal array and assigning values to it

    sortArray(tempArray, size);
    double medianValue;

    if (size % 2 == 0){ // do this if array size number is even
        printf("\nThe array is even.\n");
        // Old method
        //medianValue = (array[(size/2) - 1] + array[size/2]);
        //medianValue = medianValue/2;

        medianValue = (*(tempArray + (size/2) - 1) + *(tempArray + size/2));
        medianValue = medianValue/2;

    } else{ // do this if array size number is not even
        printf("\nThe array is not even.\n");
        // Old method
        //medianValue = array[(size+1)/2-1];

        medianValue = *(tempArray + (size + 1)/2 - 1);
    }

    return medianValue;
}

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
    printf("Select the option: \n");
}


int main() {
    int numbers[SIZE] = {9, 14, 11, 5, 8, 15, 4, 3, 7};
    const int *ptrNumbers = numbers; // Pointer with NOT editable values
    int *ptrEditNumbers = numbers; // Pointer with editable values
    int option = 0; // Stores selected option by user

    do{
        menu();
        scanf("%d", &option);

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

            default:
                printf("Please select viable option.\n");
        }
    } while ( option!=0 );

    printf("Goodbye!\n");

    return 0;
}