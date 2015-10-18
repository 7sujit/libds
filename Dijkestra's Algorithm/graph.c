#include "graph.h"
#include "heap.h"

Node *graph;
int heap_size;


AdjNode *make_node(int id, int w)
{
    AdjNode *temp = (AdjNode *) malloc (sizeof(AdjNode));
    temp->id = id;
    temp->cost = w;
    temp->next = NULL;

    return temp;
}


Node *create_graph(int size)
{
    int i;
    Node *graph = (Node *) malloc (size * sizeof(Node));

    for ( i = 0; i < size; i++)
    {
        graph[i].id = i;
        graph[i].d = INT_MAX;
        graph[i].heap_index = i;
        graph[i].visited = 0;
        graph[i].p = -1;
        graph[i].adj = NULL;
    }

    return graph;

}


void add_edge(int source, int dest, int cost)
{
    AdjNode *node = make_node(dest, cost);

    node->next = graph[source].adj;
    graph[source].adj = node;

}

void print_graph(int nodes)
{
    int i;
    AdjNode *node;

    printf("format --> {node} : (adj_node [edge_cost])\n");
    for(i = 0; i < nodes; ++i)
    {
        node = graph[i].adj;
        printf("{%d} : ",i);
        while(node)
        {
            printf("(%d[%d]) ", node->id, node->cost);
            node = node->next;
        }

        printf("\n");
    }

}


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
        adj = node->adj;

        while(adj)
        {
            if(graph[adj->id].visited == 0 &&  graph[adj->id].d > adj->cost + node->d )
            {
                decrease_key(heap, graph[adj->id].heap_index, (adj->cost + node->d) );
                graph[adj->id].p = node->id;
            }

            adj = adj->next;
        }
    }
    printf("\n");
}

void free_graph(Node *graph, int nodes)
{
    AdjNode *prev, *node;
    int i;
    
    for(i = 0; i < nodes; ++i)
    {
        node = graph[i].adj;
        while(node)
        {
            prev = node;
            node = node->next;
            free(prev);
        }
    }
    free(graph);
}
