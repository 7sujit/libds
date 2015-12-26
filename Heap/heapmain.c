#include "heap.h"

int heap_size;

int main(void)
{
    void ** heap;
    int *a;
    int i, new_val;
    int size;
    puts("enter the size of the heap ");
    scanf("%d",&size);

    heap_size = size;

    a = (int *) malloc(size * sizeof(int));
    heap = create_list(size);


    for(i = 0;i < size;scanf("%d",&a[i]), ++i);

    for(i = 0; i < size; ++i)
        heap[i] = &a[i];


    build_heap(heap);
    print_heap(heap);

    printf("%s ", "decrease_key at position and new val: ");
    scanf("%d %d", &i, &new_val);
    decrease_key(heap,i-1, new_val);
    print_heap(heap);

    return 0;
}
