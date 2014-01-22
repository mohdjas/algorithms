/* 
        Program: Mergesort (Topdown)
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-09
        Last modified:
*/

#include "sorthelper.c"

static void merge_sort(int *array, int *aux, int low, int high);
static void merge(int *array, int *aux, int low, int mid, int high);

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);        
        int array[ARRAY_SIZE];
        int aux[ARRAY_SIZE];
        init_array(array);
        print_array(array);
                        
        merge_sort_topdown(array, aux, 0, ARRAY_SIZE-1);
        print_array(array);
               
        return 0;
}

static void merge_sort_topdown(int *array, int *aux, int low, int high)
{
        int mid = (low+high)/2;
        if (high-low+1 == 1) return;
        merge_sort_topdown(array, aux, low, mid);
        merge_sort_topdown(array, aux, mid+1, high);
        merge(array, aux, low, mid, high);
}

static void merge(int *array, int *aux, int low, int mid, int high)
{
        register int i, j, k;
        
        for (k = low; k <= high; k++) { *(aux + k) = *(array + k); }
        for (i = low, j = mid + 1, k = low; k <= high; k++)
        {
                if (i > mid)                    *(array + k) = *(aux + j++);
                else if (j > high)              *(array + k) = *(aux + i++);
                else if (less(aux, i, j))       *(array + k) = *(aux + i++);
                else                            *(array + k) = *(aux + j++);
        }
}
        
