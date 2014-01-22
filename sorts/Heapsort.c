/* 
        Program: Heapsort
        Author name: Mohamed Jasim Pocha
        Email: mohd.jas@gmail.com
        Created: 2013-12-14
        Last modified:
*/

#include "sorthelper.c"

void swim(int *heap, int node)
{
        while (node >= 1 && less(heap, node/2, node))
        {
                exch(heap, node/2, node);
                node = node/2;
        }
}

void sink(int *heap, int node, int heap_size)
{
        int new;
        while (2*node <= heap_size)
        {
                new = node*2;
                if (new < heap_size && less(heap, new, new+1)) new++;                   /* New parent node is the larger child. */
                if (!less(heap, node, new)) break;                                      /* If parent is greater than or equal to larger child, we're done.*/
                exch(heap, node, new);
                node = new;
        }
}

int get_max(int *heap, int heap_size)
{
        int max = heap[1];
        exch(heap, 1, heap_size);
        sink(heap, 1, heap_size-1);
        return max;
}

void make_max_heap(int *array, int array_size)
{
        int i;
        for (i = array_size/2; i > 0; i--)
        {
                sink(array, i, array_size);
        }
           
}

void heapsort(int *array, int array_size)
{
        int i;
        make_max_heap(array, array_size);
        for (i = array_size; i > 1; i--)
        {
                array[i] = get_max(array, i);     
        }
           
                
}

int main (int argc, char *argv[])
{
        ARRAY_SIZE = atoi(argv[1]) + 1;
        int array[ARRAY_SIZE];
        init_array(array);    
        
        heapsort(array, ARRAY_SIZE);
        print_array(array);
        
        return 0;
}
