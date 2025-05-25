#include <iostream>
#define QUEUE_SIZE 5
int queue_table[QUEUE_SIZE] = {0 };
int queue_writeIndex = 0;
int queue_readIndex = 0;
int queue_elements = 0;

int isQueueEmpty(void)
{
    return (queue_elements == 0) ? 1 : 0;
}

int isQueueFull(void)
{
    return (queue_elements == (QUEUE_SIZE)) ? 1 : 0;
}

int Usun(void)
{
    if (!isQueueEmpty())
    {
        int queueRead = queue_table[queue_readIndex];
        queue_readIndex = (queue_readIndex + 1) % QUEUE_SIZE;
        queue_elements--;
        return queueRead;
    }

    return queue_table[0];
}

int Pierwszy(void)
{
    return queue_table[queue_readIndex];
}

void Wstaw(int val)
{
    if (!isQueueFull())
    {
        queue_table[queue_writeIndex] = val;
        queue_writeIndex = (queue_writeIndex + 1) % QUEUE_SIZE;
        queue_elements++;
    }
}