#include "graph.h"

EdgeList *graph;

int compare_edges(const void *a, const void *b)
{
    return ( ((EdgeList *)a)->w -  ((EdgeList *)b)->w );
}


void create_graph(int edges)
{
    int i = 0;
    int x,y,d;

    graph = (EdgeList *) malloc (edges * sizeof(EdgeList));

    while(i < edges)
    {

        scanf("%d %d %d", &x,&y,&d);
        graph[i].src = x-1;
        graph[i].dest = y-1;
        graph[i].w = d;

        ++i;
    }



}
