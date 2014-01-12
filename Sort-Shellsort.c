/* 
        Program: Shell's Sort
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
        register int i, ii, min, h = 1;
        
        while (h < ARRAY_SIZE/3) h = 3*h + 1;
        
        init_array(array);
        print_array(array);
        
        while (h >= 1)
        {        
                for (i = 0; i < ARRAY_SIZE; i++)
                {
                        ii = i;
                        while (ii >= h && less(array, ii, ii-h)) { exch(array, ii, ii-h); ii-=h; }
                }        
                print_array(array);
                h /= 3;
        }
        print_array(array);
        return 0;
}
