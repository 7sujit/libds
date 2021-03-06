#include "graph.h"
#include "heap.h"

Node *graph;
int heap_size;

void call_dijkestra(void **heap, int source , int nodes)
{
    Node *node;
    AdjNode *adj;
    int i;

    for ( i = 0; i < nodes; i++)
        heap[i] = &graph[i];

    decrease_key(heap, source, 0);


    while(heap_size)
    {
        node = (Node *) extract_min(heap);
        if(node->d == INT_MAX) // check for disconnected paths
            break;

        adj = node->adj;
        graph[node->id].visited = 1;

        while(adj)
        {
            if( (!graph[adj->id].visited) && graph[adj->id].d > adj->cost + node->d )
            {
                decrease_key(heap, graph[adj->id].heap_index, (adj->cost + node->d) );
                graph[adj->id].p = node->id;
            }

            adj = adj->next;
        }
    }
}
