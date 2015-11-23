#include "heap.h"

// global variables
int heap_size;

/* <---- DO SOME MANIPULATION FOR THE ADT ----> */

int cmp(const void *a, const void *b)
{
	return (*(int *)a) - (*(int *)b);
}

void update_key(void **heap, int index, int new_val)
{
	if(new_val < *(int *)heap[index])
		*(int *)heap[index] = new_val;
}

/* <---- DON'T CHANGE ANYTHING BELOW THIS, IF NOT URGENT -----> */

void **create_list(int size)
{
	void **list = (void **) malloc(size * sizeof(void *));
	heap_size = size;
	return list;
}

int left(int index)
{
	return 2 * index + 1;
}

int right(int index)
{
	return 2 * index + 2;
}

int parent(int index)
{
	return (index - 1) / 2;
}

void heapify(void **heap,int index)
{
	int smaller = index;
	void *temp;

	if(left(index) < heap_size && cmp(heap[smaller], heap[left(index)]) > 0 ) // left-child is smaller than parent
		smaller = left(index);

	if(right(index) < heap_size && cmp(heap[smaller], heap[right(index)]) > 0 ) // right-child is the smallest among all three
		smaller = right(index);

	if(smaller != index)
	{
		// swap two nodes
		temp = heap[index];
		heap[index] = heap[smaller];
		heap[smaller] = temp;

		heapify(heap, smaller);
	}
}


void build_heap(void **heap)
{
	int i;

	for(i = heap_size/2 ; i >= 0; --i)
		heapify(heap, i);
}

void *extract_min(void **heap)
{
	if(heap_size < 0)
		return NULL;

	void *temp = heap[0];
	heap[0] = heap[heap_size - 1];
	heap[heap_size - 1] = temp;

	heap_size = heap_size - 1;

	heapify(heap, 0);

	return temp;
}


void decrease_key(void **heap, int index,int new_val)
{
	void *temp;

	update_key(heap, index, new_val);

	while( parent(index) >= 0 && cmp(heap[index], heap[parent(index)]) < 0)
	{
		temp = heap[parent(index)];
		heap[parent(index)] = heap[index];
		heap[index] = temp;

		index = parent(index);
	}
}


void print_heap(void **heap)
{
    int i;
    for(i = 0 ;i < heap_size; printf("%d ",*((int *)(heap[i]))) , ++i);

	printf("\n");
}
