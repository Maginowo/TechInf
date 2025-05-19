//#include <iostream>
#include <stdio.h>
#include "Stack.h"
#include "Kolejka.h"

void menu(void)
{
    printf("\n");
    printf("11/12 - poloz liczbe na stosie/kolejce (Push)\n");
    printf("21/22 - odczytaj wartosc ze szczytu stosu/poczatku kolejki (Top)\n");
    printf("31/32 - zdejmij liczbe ze stosu/kolejki (Pop)\n");
    printf("41/42 - sprawdz czy stos/kolejka jest pusty\n");
    printf("51/52 - sprawdz czy stos/kolejka jest pelny\n");
    printf("6 - koniec programu\n");
    printf("\n");
}

int main()
{
    int tempStos = 0;
    int tempKolejka = 0;
    int option = 0;
    printf("STOS - implementacja w tablicy statycznej\n");
    while (1)
    {
        menu();
        scanf("%d", &option);


        switch (option)
        {
            case 11:
                if ( !isStackFull() ){
                    printf("Podaj wartosc: ");
                    scanf("%d", &tempStos);
                    Push(tempStos);
                }
                else {
                    printf("operacja niedozwolona STOS pelny!!!\n\n");
                }

                break;

            case 21:
                if (!isStackEmpty()) {
                    tempStos = Top();
                    printf("Odczytana wartosc: %d", tempStos);
                }
                else {
                    printf("operacja niedozwolona STOS pusty!!!\n\n");
                }

                break;

            case 31:
                if (!isStackEmpty()) {
                    tempStos = Pop();
                    printf("Odczytana wartosc: %d", tempStos);
                }
                else {
                    printf("operacja niedozwolona STOS pusty!!!\n\n");
                }
                break;

            case 41:
                if (isStackEmpty()) {
                    printf("STOS jest pusty.\n");
                }
                else {
                    printf("STOS nie jest pusty.\n");
                }
                break;

            case 51:
                if (isStackFull()) {
                    printf("STOS jest pelny.\n");
                }
                else {
                    printf("STOS nie jest pelny.\n");
                }
                break;

            case 12:
                if ( !isQueueFull() ){
                    printf("Podaj wartosc: ");
                    scanf("%d", &tempKolejka);
                    Wstaw(tempKolejka);
                }
                else {
                    printf("operacja niedozwolona - kolejka jest pelna!\n\n");
                }

                break;

            case 22:
                if (!isQueueEmpty()) {
                    tempKolejka = Pierwszy();
                    printf("Odczytana wartosc: %d", tempKolejka);
                }
                else {
                    printf("operacja niedozwolona - kolejka jest pusta!\n\n");
                }

                break;

            case 32:
                if (!isQueueEmpty()) {
                    tempKolejka = Usun();
                    printf("Odczytana wartosc: %d", tempKolejka);
                }
                else {
                    printf("operacja niedozwolona - kolejka jest pusta!\n\n");
                }
                break;

            case 42:
                if (isQueueEmpty()) {
                    printf("Kolejka jest pusta.\n");
                }
                else {
                    printf("Kolejka nie jest pusta.\n");
                }
                break;

            case 52:
                if (isQueueFull()) {
                    printf("Kolejka jest pelna.\n");
                }
                else {
                    printf("Kolejka nie jest pelna.\n");
                }
                break;

            case 6:
                //zakonczenie programu
                return 0;

            default:
                printf("Wybierz wlasciwa opcje.\n\n");
                break;
        }
    }

    return 0;
}