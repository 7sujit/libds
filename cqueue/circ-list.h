#include <stdlib.h>
#include <stdio.h>

#ifndef _H_CIRC
#define _H_CIRC

typedef struct CircListNode
{
  void *item;
  struct CircListNode *next;
}clist_node;

typedef struct CircListHead
{
  int total_items;  // count of the total items in the list
  struct CircListHead *list; // pointer to the head/tail of the cric-list
}clist_head;


/*
  FUNCTION TO CREATE THE LIST HEAD
  --> First have to call this function in order to create a circ-list
  --> List Head keeps tracks of the total counts and the pointer to the head/tail
  --> return type is `cqueue_head` and takes parameter `void`
*/
clist_head *create_circ_list(void);

void add_item(clist_head *, void * );

void del_item(clist_head *);

int count_items(clist_head *);

int is_empty(clist_head *head);

clist_node *create_node(void *item);

#endif
