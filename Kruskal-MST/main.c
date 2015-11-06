#include "ufind.h"
#include "graph.h"

UFindNode *uset;
EdgeList *graph;

int main(void)
{
    int x,y,z,i;
    int edges, nodes, edge_count = 0;;
    int *sp_tr_edge_list = NULL;
    scanf("%d %d", &nodes, &edges);
    create_ufind_ds(edges);
    create_graph(edges);

    sp_tr_edge_list = (int *) malloc ((nodes - 1) * sizeof(int));

    qsort(graph, edges, sizeof(EdgeList), compare_edges);

    for(edge_count = 0, i = 0; i < edges; ++i)
    {
        if(! same_set(graph[i].src, graph[i].dest) )
        {
            sp_tr_edge_list[edge_count] = i;
            ++edge_count;

            make_union(graph[i].src, graph[i].dest);
        }

    }

    puts("printing edgelist : ");
    for(i = 0; i < nodes - 1; ++i)
    {
        printf("%d-%d (%d)\n", 1+graph[sp_tr_edge_list[i]].src,1+graph[sp_tr_edge_list[i]].dest, graph[sp_tr_edge_list[i]].w);
    }

    return EXIT_SUCCESS;
}
