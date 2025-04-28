#include <iostream>
#define SIZE 10

void printElements(const int *ptrArray, int size){
    printf("Array Contents:\n");
    for(int i = 0;i<size;i++){
        printf("%d, ", *(ptrArray + i));
    }
    printf("\n");
}

void setElements(int *array, int size){
    printf("Write numbers into the array: ");
    for(int i = 0;i<SIZE;i++){
        //std::cin >> array[i];
        scanf("%d", array + i);
    }
}

int findMaximumValue(const int *array, int size){
    int maxValue = *(array);
    for(int i = 0; i < size; i++){
        if(maxValue<*(array + i)){ maxValue = *(array + i); }
    }
    return maxValue;
}

int findMinimumValue(const int *array, int size){
    int minValue = *(array);
    for(int i = 0; i < size; i++){
        if(minValue>*(array + i)){ minValue = *(array + i); }
    }
    return minValue;
}

double calculateAverageValue(const int array[], int size){
    double arraySum = 0;
    for(int i = 0; i < size; i++){
        arraySum += *(array + i);
    }
    return arraySum/size;
}

void sortArray(int *array, int size){
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

double calculateMedianValue(int *array, int size){
    sortArray(array, size);
    double medianValue;

    if (size % 2 == 0){ // do this if array size number is even
        printf("\nThe array is even.\n");
        // Old method
        //medianValue = (array[(size/2) - 1] + array[size/2]);
        //medianValue = medianValue/2;

        medianValue = (*(array + (size/2) - 1) + *(array + size/2));
        medianValue = medianValue/2;

    } else{ // do this if array size number is not even
        printf("\nThe array is not even.\n");
        // Old method
        //medianValue = array[(size+1)/2-1];

        medianValue = *(array + (size + 1)/2 - 1);
    }

    return medianValue;
}

int main() {
    int numbers[SIZE] = {9, 14, 11, 5, 8, 16, 4, 3, 7, 18};

    //setElements(numbers, SIZE);

    printElements(numbers, SIZE);
    printf("\nSorting...\n");
    sortArray(numbers, SIZE);
    printElements(numbers, SIZE);

    printf("\nMinimum value is: %d\n", findMinimumValue(numbers, SIZE));
    printf("Maximum value is: %d\n", findMaximumValue(numbers, SIZE));
    printf("Average value is: %.2lf\n", calculateAverageValue(numbers, SIZE));
    printf("Median value is: %.2lf\n", calculateMedianValue(numbers, SIZE));

    return 0;
}