#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#ifndef _H_CGRAPH
#define _H_CGRAPH

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct AdjList
{
	int id;
	struct AdjList *next;
}AdjList;

typedef struct NodeList
{
	int d;

    int d_time;
    int f_time;
    int low;
    
    int p;
	int child_count;

    int visited;

    struct AdjList *next;
}NodeList;

NodeList *build_graph(int nodes);

void add_edge_d(NodeList *g, int src, int dest);
void add_edge(NodeList *g, int src, int dest);

void print_graph(NodeList *graph, int nodes);
void free_graph(NodeList *graph, int nodes);

#endif
