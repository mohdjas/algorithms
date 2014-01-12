/* 
        Program: Mergesort (Bottom-up)
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-09
        Last modified:
*/

#include "sorthelper.c"

static void merge_sort_bottomup(int *array, int *aux, int low, int high);
static void merge(int *array, int *aux, int low, int mid, int high);

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);        
        int array[ARRAY_SIZE];
        int aux[ARRAY_SIZE];
        init_array(array);
        
        clock_t start, end;
        double cpu_time_used;
        start = clock();     
                   
        merge_sort_bottomup(array, aux, 0, ARRAY_SIZE-1);
        
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        printf("%f\n", cpu_time_used);
               
        return 0;
}

static void merge_sort_bottomup(int *array, int *aux, int low, int high)
{
        unsigned int i, ii;
        for (i = 1; i < ARRAY_SIZE; i *= 2)
        {
                for (ii = 0; ii < ARRAY_SIZE-i; ii += i*2)
                {
                        merge(array, aux, ii, ii+i-1, (ii+i+i-1) < (ARRAY_SIZE-1) ? (ii+i+i-1) : (ARRAY_SIZE-1));
                        /*merge(array, auxiliary array,
                        		start_of_first_array, start_of_first_array+subarray_size-1, end_of_second_array);
                        */
                }
        }
}

static void merge(int *array, int *aux, int low, int mid, int high)
{
        register unsigned int i, j, k;
        
        for (k = low; k <= high; k++) { *(aux + k) = *(array + k); }
        for (i = low, j = mid + 1, k = low; k <= high; k++)
        {
                if (i > mid)                    *(array + k) = *(aux + j++);
                else if (j > high)              *(array + k) = *(aux + i++);
                else if (less(aux, i, j))       *(array + k) = *(aux + i++);
                else                            *(array + k) = *(aux + j++);
        }
}
        
