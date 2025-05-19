#define KOLEJKA_SIZE 5
int kolejka_table[KOLEJKA_SIZE] = { 0 };
int kolejka_index = 0;

int isKolejkaEmpty(void)
{
    return (kolejka_index == 0) ? 1 : 0;
}

int isKolejkaFull(void)
{
    return (kolejka_index == (KOLEJKA_SIZE)) ? 1 : 0;
}

int Usun(void)
{
    if (!isKolejkaEmpty())
    {
        int pierwszyWyraz = kolejka_table[0];
        for(int i = 0; i < KOLEJKA_SIZE; i++){
            kolejka_table[i] = kolejka_table[i+1];
            kolejka_index--;
        }
        return pierwszyWyraz;
    }

    return kolejka_table[0];
}

int Pierwszy(void)
{
    return kolejka_table[0];
}

void Wstaw(int val)
{
    if (!isKolejkaFull())
    {
        kolejka_table[kolejka_index] = val;
        kolejka_index++;
    }
}