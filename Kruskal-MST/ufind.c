#include "ufind.h"

UFindNode *uset;


void create_ufind_ds(int size)
{
    int i;

    UItem *item = NULL;
    uset = (UFindNode *) calloc (size, sizeof(UFindNode));

    for(i = 0; i < size; ++i)
    {
        uset[i].set_id = i;
        uset[i].size = 1;

        item = (UItem *) malloc (sizeof(UItem));
        item->id = i;
        item->next = NULL;
        uset[i].list_head = uset[i].list_tail = item;
    }

}


int find(int item_id)
{
    return (uset[item_id].set_id);
}

int same_set(int first, int second)
{
    return (uset[first].set_id == uset[second].set_id);
}

void make_union(int first, int second)
{
    int large, small;

    if(same_set(first,second))
        return;

    if( uset[uset[first].set_id].size >=  uset[uset[second].set_id].size)
    {
        large = uset[first].set_id;
        small = uset[second].set_id;
    }
    else
    {
        small = uset[first].set_id;
        large = uset[second].set_id;
    }

    UItem *temp_list = uset[small].list_head;

    while(temp_list)
    {
        uset[temp_list->id].set_id = large;
        temp_list = temp_list->next;
    }

    (uset[large].list_tail)->next = uset[small].list_head;
    uset[large].list_tail = uset[small].list_tail;
    uset[large].size += uset[small].size;

    uset[small].size = 0;
    uset[small].list_head = uset[small].list_tail = NULL;

}


void print_ds(int size)
{
    int i;
    UItem *temp;

    for(i = 0; i < size; ++i)
    {
        printf("{ ");
        temp = uset[i].list_head;

        while(temp)
        {
            printf("(%d) ", temp->id);
            temp = temp->next;
        }
        printf("}\n");
    }
}
