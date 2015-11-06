#include <stdlib.h>
#include <stdio.h>

#ifndef _H_UFIND
#define _H_UFIND

typedef struct UItem
{
    int id;
    struct UItem *next;
}UItem;

typedef struct UFindNode
{
    int set_id;
    int size;
    struct UItem *list_head, *list_tail;
}UFindNode;


void create_ufind_ds(int size);
int find(int item_id);
void make_union(int first, int second);
void print_ds(int size);
#endif
