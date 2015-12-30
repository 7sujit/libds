#include "circ-list.h"

clist_head *create_circ_list(void)
{
  clist_head *head = (clist_head *) malloc (sizeof(clist_head));
  head->total_items = 0;
  head->list = NULL;

  return head;
}

int is_empty(clist_head *head)
{
  return ( (head->total_items == 0)? 0 : 1);
}

clist_node *create_node(void *item)
{
  clist_node *new_node = (clist_node *) malloc (sizeof(clist_node));
  new_node->item = item;
  new_node->next = NULL;

  return new_node;
}

void add_item(clist_head *header, void *item)
{
  clist_node *new_node = create_node(item);


  ++(header->total_items);
}

int count_items(clist_head *clist)
{
  return clist->total_items;
}

void print_list(clist_head *header) // for now printing int values
{
  int i = count_items(header);
  clist_node = header->list;

  for( ; i > 0; --i )
  {
    printf("%d, ",((int *)clist_node)->item);
    clist_node = clist_node->next;
  }
}
