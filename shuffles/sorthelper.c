#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int ARRAY_SIZE = 0;

int less(int *array, int i, int j)
{
        return *(array + i) < *(array + j);
}

void exch(int *array, int i, int j)
{
        int temp;
        temp = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = temp;
}

void print_array(int *array)
{
        int i;
        for (i = 0; i < ARRAY_SIZE; i++)
        {
                printf("%3d", *(array+i));
        }
        printf("\n");
}

void init_array(int *array)
{
        int i;
        srand(time(NULL));
        for (i = 0; i < ARRAY_SIZE; i++)
        {
                *(array + i) = rand()%100 + 1;
        }
}
