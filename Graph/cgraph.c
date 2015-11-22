#include "cgraph.h"


NodeList *build_graph(int nodes)
{
    int i;
    
    NodeList *g = (NodeList *) malloc (nodes * sizeof(NodeList));

    for(i = 0; i < nodes; ++i)
    {
    	g[i].d = 0;
		g[i].d_time = 0;
		g[i].f_time = 0;
        g[i].p = -1;
		g[i].child_count = 0;
		g[i].visited = 0;
        g[i].next = NULL;
    }
    return g;
}

void add_edge(NodeList *g, int src, int dest)
{// undirected edge

	add_edge_d(g, src, dest);
	add_edge_d(g, dest, src);
}

void add_edge_d(NodeList *g, int src, int dest)
{
	AdjList *new_edge = (AdjList *) malloc (sizeof(AdjList));
    new_edge->id = dest;
	new_edge->next = NULL;

	new_edge->next = g[src].next;
    g[src].next = new_edge;

}


void print_graph(NodeList *graph, int nodes)
{
    int i;    
    AdjList *temp;
    for (i = 0; i < nodes; ++i)
    {
        temp = graph[i].next;
        printf("%d : ", i);
        while(temp)
        {
            printf("%d ", temp->id);
            temp = temp->next;
        }
       	 printf("\n");
    }

}

void free_graph(NodeList *graph, int nodes)
{
	AdjList *temp, *fr;
	int i;

	for (i = 0; i < nodes; ++i)
	{
		temp = graph[i].next;
		while(temp)
		{
			fr = temp;
			temp = temp->next;
			free(fr);
		}
	}	

	free(graph);
}
