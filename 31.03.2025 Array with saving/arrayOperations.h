//
// Created by Student on 31.03.2025.
//

#ifndef INC_31_03_255351_ARRAYOPERATIONS_H
#define INC_31_03_255351_ARRAYOPERATIONS_H

void printElements(const int *ptrArray, const int size);

void setAllElements(int *array, const int size);

void setTheElement(int *array, const int size);

int findMaximumValue(const int *array, const int size);

int findMinimumValue(const int *array, const int size);

double calculateAverageValue(const int array[], const int size);

void sortArray(int *array, const int size);

void copyArray(const int *originalArray, int *newArray, const int size);

void previewArrayAsSorted(const int *array, const int size);

double calculateMedianValue(const int *array, const int size);

int saveArrayToFile(const int *array, const int size);

int restoreArrayFromFile(int *array, const int size);

#endif //INC_31_03_255351_ARRAYOPERATIONS_H
