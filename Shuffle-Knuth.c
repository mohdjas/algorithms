/* 
        Program: Knuth Shuffle
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-09
        Last modified:
*/

#include "sorthelper.c"

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]);
        int array[ARRAY_SIZE];
        register int i = 0, r;
        
        for (i = 0; i < ARRAY_SIZE; i++) { array[i] = i+1; }
            
        for (i = 1; i < ARRAY_SIZE; i++)
        {
                srand(time(NULL));
                r = rand()%i;
                exch(array, i, r);
        }
        print_array(array);
        return 0;
}
