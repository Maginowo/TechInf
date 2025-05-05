#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void parametersInfo(){
    printf("Command format: <number1> <operation> <number2>\n");
    printf("Please provide parameters.\n");
    printf("Possible operations: add, sub, mul, div\n");
}

int saveToLog(const int number1, const char *operation, const int number2){
    FILE * fptr;

    fptr = fopen("..//plik.txt", "a");
    if (!fptr){ return 1; }

    // Creating current time char
    time_t currentTime = time(NULL);
    char time[50];
    strftime(time, sizeof(time), "%A, %B, %d, %Y", localtime(&currentTime));

    fprintf(fptr, "[%s]: %d %s %d\n", time, number1, operation, number2);
    fclose(fptr);

    return 0;
}

int add(const int number1, const int number2){
    return number1 + number2;
}
int subtract(const int number1, const int number2){
    return number1 - number2;
}
int multiply(const int number1, const int number2){
    return number1 * number2;
}
int divide(const int number1, const int number2){
    return number1 / number2;
}

int main(int argc, char const *argv[]) {
    int number1, number2;
    if (argc < 4){
        parametersInfo();
        return 0;
    }
    number1 = atoi(argv[1]);
    number2 = atoi(argv[3]);

    printf("Operation: %d %s %d\n", number1, argv[2], number2);
    saveToLog(number1, argv[2], number2);

    //logOperation();

    if(strcmp(argv[2], "add") == 0){
        printf("Result: %d", add(number1, number2));
    } else if(strcmp(argv[2], "sub") == 0){
        printf("Result: %d", subtract(number1, number2));
    } else if(strcmp(argv[2], "mul") == 0){
        printf("Result: %d", multiply(number1, number2));
    } else if(strcmp(argv[2], "div") == 0){
        printf("Result: %d", divide(number1, number2));
    }
    else {
        parametersInfo();
    }


    return 0;
}