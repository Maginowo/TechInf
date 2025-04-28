#include <iostream>
#include <random>

int randomNumberGen(int a, int b){
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);
    return distrib(gen);
}

void smallLetters(char *symbols){
    while (*symbols){
        if('A' <= *symbols && *symbols <= 'Z'){
            *symbols += ('a' - 'A');
        }
        symbols++;
    }
}

void largeLetters(char *symbols){
    while (*symbols){
        if('a' <= *symbols && *symbols <= 'z'){
            *symbols -= ('a' - 'A');
        }
        symbols++;
    }
}

void deleteSpecialSymbols(char *symbols){
    while (*symbols){
        if('!' <= *symbols && *symbols <= '/'){ *symbols = 0x20; }
        symbols++;
    }
}

void deleteNumbers(char *symbols){
    while(*symbols){
        if('0' <= *symbols && *symbols <= '9'){ *symbols = 0x20; }
        symbols++;
    }
}

//void randomSymbols(char *symbols){
//    int randomNumber;
//    char randomSymbol[5];
//    while(*symbols){
//        randomNumber = randomNumberGen(20, 255);
//        randomSymbol =
//        if('0' <= *symbols && *symbols <= '9'){ *symbols = randomNumber; }
//        symbols++;
//    }
//}

int textLength(char *symbols){
    int length = 0;
    while(*symbols){
        length++;
        symbols++;
    }
    return length;
}

int main() {
    char symbols[] = "12345 Those ARE words! And THESE are SYMBOLS: #$%+-,.!";

    printf("Normal string:\t%s\n", symbols);
    smallLetters(symbols);
    printf("Small Letters:\t%s\n", symbols);

    largeLetters(symbols);
    printf("Large letters:\t%s\n", symbols);

    smallLetters(symbols);
    deleteSpecialSymbols(symbols);
    printf("No symbols:\t%s\n", symbols);

    deleteNumbers(symbols);
    printf("No numbers:\t%s\n", symbols);

//    randomSymbols(symbols);
//    printf("Random symbols:\t%s\t", symbols);

    printf("Size: %d", textLength(symbols));

    return 0;
}