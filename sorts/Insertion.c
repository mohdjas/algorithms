/* 
        Program: Insertion Sort
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-09
        Last modified: 2013-12-09
*/

#include "sorthelper.c"

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);
        
        int array[ARRAY_SIZE];
        register int i, ii, min;
        init_array(array);
        
        clock_t start, end;
        double cpu_time_used;
        start = clock();     
                   
        for (i = 1; i < ARRAY_SIZE; i++)
        {
                ii = i;
                while (ii > 0 && less(array, ii, ii-1)) { exch(array, ii, ii-1); ii--; }
        }        
        
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        printf("%f\n", cpu_time_used);

        return 0;
}
