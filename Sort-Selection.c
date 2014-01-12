/* 
        Program: Selection Sort
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-13
        Last modified:
*/

#include "sorthelper.c"

void selection_sort(int *array, int low, int high)
{
    int i, ii;
    int min;
    for (i = 0; i <= high; i++)
    {
        min = i;
        for (ii = i+1; ii <= high; ii++)
        {
            if (less(array, ii, min)) min = ii;
        }
        exch(array, min, i);
    }
}


int main (int argc, char *argv[])
{
    ARRAY_SIZE = atoi(argv[1]);
    int array[ARRAY_SIZE];
    init_array(array);
    selection_sort(array, 0, ARRAY_SIZE-1);
    return 0;
}
