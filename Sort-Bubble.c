/* 
        Program: Bubble Sort
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-10
        Last modified: 2013-12-10
*/

#include "sorthelper.c"

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);
        
        int array[ARRAY_SIZE];
        register int i, ii;
        init_array(array);
        
        clock_t start, end;
        double cpu_time_used;
        start = clock();     
                
        for (i = 0; i < ARRAY_SIZE; i++)
        {
                for (ii = 0; ii < ARRAY_SIZE-i; ii++)
                {
                        if (less(array, ii+1, ii)) { exch(array, ii, ii+1); }
                }
        }        
        print_array(array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        printf("%f\n", cpu_time_used);

        return 0;
}
