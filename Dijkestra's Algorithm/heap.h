#include <stdio.h>
#include <stdlib.h>

#ifndef _H_HEAP
#define _H_HEAP

/******************************************************************************
    WARNING :   MUST HAVE TO PREPARE THE COMPARATOR FUNCTION
                AND THE UPDATER FUNCTION.


 ******************************************************************************/

int cmp(const void *a, const void *b);

void **create_list(int size);

void build_heap(void **list);

void heapify(void **heap,int index);

void *extract_min(void **heap);

void decrease_key(void **heap, int index, int new_val);
void update_key(void **heap, int index, int new_val);

void print_heap(void **heap);

#endif
