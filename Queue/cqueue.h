#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifndef _H_CQUEUE
#define  _H_CQUEUE


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct LList
{
    int count;
    struct Node *head, *tail;
}LList;

int is_empty(LList *list);

void print_list(LList *list);

void insert_front(LList *list, int data);

void insert_end(LList *list, int data);

void enqueue(LList *list, int data);

int dequeue(LList *list);

LList *make_list(void);

#endif
