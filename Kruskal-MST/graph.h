#include <stdio.h>
#include <stdlib.h>

#ifndef _H_GRAPH
#define _H_GRAPH


typedef struct Edge
{
    int src, dest;
    int w;
}EdgeList;


int compare_edges(const void *a, const void *b);
void create_graph(int edges);

#endif
