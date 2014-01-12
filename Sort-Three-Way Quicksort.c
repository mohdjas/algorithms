/* 
        Program: Three-Way Quicksort
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-13
        Last modified:
*/

#include "sorthelper.c"

void quicksort_3way(int *array, int low, int high)
{
        register i = low, lt = low, gt = high, p = array[low];
        
        if (low >= high) return;
        
        while (i <= gt)
        {
                if (array[i] < p)  { exch(array, i++, lt++); }
                if (array[i] > p)  { exch(array, i, gt--); }
                if (array[i] == p) { i++; }
        }
          
        quicksort_3way(array, low, lt-1);
        quicksort_3way(array, gt+1, high);
}

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);
        int array[ARRAY_SIZE];
        init_array(array);
        
        clock_t start, end;
        double cpu_time_used;
        start = clock(); 
                
        quicksort_3way(array, 0, ARRAY_SIZE-1);
                
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);
        
        return 0;
}
