#include "graph.h"
#include "heap.h"

Node *graph;

int main(void)
{
    int nodes;
    int edges;
    int source, dest, cost;
    int i;
    void *heap;

    // printf("%s", "enter no. of nodes and edges : ");
    scanf("%d %d", &nodes, &edges);
    graph = create_graph(nodes);
    heap = create_list(nodes);

    i = edges;
    while(i --)
    {
        // printf("%s", "source - dest - cost : : ");
        scanf("%d %d %d", &source, &dest, &cost);
        add_edge(source, dest, cost);
    }

    print_graph(nodes);
    // printf("%s", "enter the source : ");
    scanf("%d", &source);


    call_dijkestra(heap, source, nodes);
    printf("\n" );

    for(i = 0; i < nodes; ++i)
    {
    	if(i == source)
    	   printf("%d : %d (source)\n", i , graph[i].d);

        else if(graph[i].id != source && graph[i].p == -1)
        {
            printf("%d : %s (p : %d)\n", i , "infi", graph[i].p);
            continue;
        }
        else
            printf("%d : %d (p : %d)\n", i , graph[i].d, graph[i].p);
    }

    free_graph(graph, nodes);
    free(heap);

    return 0;
}
