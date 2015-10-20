#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef _H_GRAPH
#define _H_GRAPH


typedef struct Node
{
    int id;
    int heap_index;

    int d;
    int p;

    struct AdjNode *adj;
}Node;

typedef struct AdjNode
{
    int id;
    int cost;
    struct AdjNode *next;
}AdjNode;




Node *create_graph(int size);
AdjNode *make_node(int id, int w);

void add_edge(int source, int dest, int cost); // directed edge

void call_dijkestra(void **heap, int source, int nodes);

void print_graph(int nodes);

void free_graph(Node *graph, int nodes);

#endif
