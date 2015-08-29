#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _H_STACK
#define _H_STACK

typedef struct stack_head
{
    int element_count;
    void *next;
}stack_t;

typedef struct stack_node
{
    void *element;
    void *next;
}stack_element_t;

void swap(void *first,  void *second, int size);

stack_t *create_stack();

void push(stack_t *curr_stack,void *obj);

void *pop(stack_t *curr_stack);
/*
    *(( <data_type> *)pop_element) to get the value
*/

#endif
