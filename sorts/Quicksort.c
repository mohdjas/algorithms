/* 
        Program: Quicksort
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-10
        Last modified:
*/

#include "sorthelper.c"

void quicksort(int *array, int low, int high)
{
        register i = low, j = high+1;
        if (low >= high) return;
        while (1)
        {
                while(less(array, ++i, low)) if (i == high) break;
                while(less(array, low, --j)) if (j == low)  break;
                if (i >= j) break;
                exch(array, i, j);
        }
        exch(array, low, j);    
        quicksort(array, low, j-1);
        quicksort(array, j+1, high);
}

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);
        int array[ARRAY_SIZE];
        init_array(array);
        
        clock_t start, end;
        double cpu_time_used;
        start = clock(); 
                
        quicksort(array, 0, ARRAY_SIZE-1);
        
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);
        
        return 0;
}
