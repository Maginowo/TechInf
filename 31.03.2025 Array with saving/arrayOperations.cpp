#include <iostream>

void printElements(const int *ptrArray, const int size){
    printf("Array Contents:\n");
    for(int i = 0;i<size;i++){
        printf("%d, ", *(ptrArray + i));
    }
    printf("\n");
}

void setAllElements(int *array, const int size){
    printf("Write numbers into the array: ");
    for(int i = 0;i<size;i++){
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

int saveArrayToFile(const int *array, const int size){
    FILE * fptr;

    fptr = fopen("..//plik.txt", "w");
    if (!fptr){ return 1; }

    for(int i = 0; i<size; i++){
        fprintf(fptr, "%d\n", *(array + i));
    }

    fclose(fptr);

    return 0;
}

int restoreArrayFromFile(int *array, const int size){
    FILE * fptr = NULL;
    char fileLine[20];
    int currentLine = 0;

    fptr = fopen("..//plik.txt", "r");
    if (!fptr){ return 1; }

    for (int i = 0; i < size; ++i){
        if (fscanf(fptr, "%d", array + i) != 1){
            fclose(fptr);
            return 2; // Error in data reading.
        }
    }
//    while ((!feof(fptr)) && (currentLine != size)){
//        fgets(fileLine, 100, fptr);
//        if (!feof(fptr)){
//            *(array + currentLine) = atoi(fileLine);
//        }
//
//        currentLine++;
//    }


    fclose(fptr);

    return 0;
}