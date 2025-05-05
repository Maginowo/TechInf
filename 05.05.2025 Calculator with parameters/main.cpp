#include <stdio.h>
#include <stdlib.h>
void usage(const char *program_name) {
    printf("Sposob uzycia: %s <komunikat> <#powtorzen>\n", program_name);
    exit(1);
}
int main(int argc, char const *argv[]) {
    int i, count;
    if (argc < 3)
        usage(argv[0]);
    count = atoi(argv[2]);
    printf("Powtarzam %d razy..\n", count);
    for (i = 0; i < count; i++)
        printf("%3d - %s\n", i, argv[1]);
    return 0;
}