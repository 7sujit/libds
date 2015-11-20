#include "cqueue.h"


int is_empty(LList *list)
{
    return !(list->count);
}

LList *make_list(void)
{
    LList *new_list = (LList *) malloc (sizeof(LList));
    new_list->head = new_list->tail = NULL;
    new_list->count = 0;

    return new_list;
}

Node *make_node(int data)
{
    Node *temp = (Node *) malloc (sizeof(Node));
    temp->next = NULL;
    temp->data = data;

    return temp;
}

void insert_front(LList *list, int data)
{
    Node *new_node = make_node(data);

    if(! list->head)
    {
        list->head = list->tail = new_node;
        list->count = 1;
        return ;
    }

    new_node->next = list->head;
    list->head = new_node;
    ++(list->count);
}

void insert_end(LList *list, int data)
{
    Node *new_node = make_node(data);

    if(! list->tail)
    {
        list->head = list->tail = new_node;
        list->count = 1;
        return ;
    }

    list->tail->next = new_node;
    list->tail = new_node;
    ++(list->count);
}

void enqueue(LList *list, int data)
{
    insert_end(list, data);
}

int dequeue(LList *list)
{

    Node *temp = list->head;
    int val;

    if(! list->count)
        return INT_MIN;

    val = list->head->data;
    list->head = list->head->next;
    if(! list->head)
        list->tail = NULL;

    --(list->count);

    free(temp);

    return val;

}

void print_list(LList *list)
{
    Node *head = NULL;
    if(! list->count)
        return;

    head = list->head;

    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }

}
