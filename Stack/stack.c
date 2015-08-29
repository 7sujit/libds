#include "stack.h"

stack_t *create_stack()
{
    stack_t *new_stack = (stack_t *) malloc (sizeof(stack_t));
    new_stack->element_count = 0;
    new_stack->next = NULL;

    return new_stack;
}

void push(stack_t* curr_stack,void *obj)
{
    // create new stack element and point it to the object
    stack_element_t *new_element = (stack_element_t *) malloc(sizeof(stack_element_t));
    new_element->element = obj;
    new_element->next = curr_stack->next;
    curr_stack->next = new_element;

    ++curr_stack->element_count;

}


void *pop(stack_t *curr_stack)
{
    if(! curr_stack->next)
        return NULL;

    stack_element_t *top_element = (stack_element_t *)(curr_stack->next);
    void *curr_element = top_element->element;
    curr_stack->next = ((stack_element_t *)(curr_stack->next))->next;
    -- curr_stack->element_count;
    free(top_element);

    return curr_element;
}

void *peep_stack(stack_t *curr_stack)
{
    if(! curr_stack->next)
        return NULL;

    stack_element_t *top_element = (stack_element_t *)(curr_stack->next);
    return top_element->element;
}


void swap( void *first,  void *second, int size)
{
    void *temp = (void *) malloc(size);
    memcpy(temp, first, size);
    memcpy(first, second, size);
    memcpy(second, temp, size);
}


/*
    creates a stack header which will hold 'stack_top'
    whichi will be pointing to the top of the stack.
    another variable 'element_count' storing the no. of elements
    in the stack currently.
*/

/*
    PUSH FUNCTION CAN BE APPLIED USING BY PUSHING A POINTER
    TO THE OBJECT, IN THIS CASE WE WILL BE PUSHING POINTER OF
    TYPE `void *`
*/
