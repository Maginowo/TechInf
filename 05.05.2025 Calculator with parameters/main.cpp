#include <stdio.h>
int main(int argc, char const *argv[]) {
    int i;
    printf("Podano %d argumentow:\n", argc);
    for (i = 0; i < argc; i++) {
        printf("Argunent #%d\t-\t%s\n", i, argv[i]);
    }
    return 0;
}