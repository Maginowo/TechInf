#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parametersInfo(){
    printf("Command format: <number1> <operation> <number2>\n");
    printf("Please provide parameters.\n");
    printf("Possible operations: add, sub\n");
}

int add(int number1, int number2){
    return number1 + number2;
}
int subtract(int number1, int number2){
    return number1 - number2;
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

    if(strcmp(argv[2], "add") == 0){
        printf("Result: %d", add(number1, number2));
    } else if(strcmp(argv[2], "sub") == 0){
        printf("Result: %d", subtract(number1, number2));
    }
    else {
        parametersInfo();
    }


    return 0;
}