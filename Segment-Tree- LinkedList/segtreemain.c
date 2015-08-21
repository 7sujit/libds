#include "segtree.h"


int main(void)
{
    int *input = NULL;
    int size,m;
    int store_max,store_freq;
    int i,x,y;

    scanf("%d %d", &size, &m);
    input = (int *) malloc(size * sizeof(int));

    for(i = 0; i < size; ++i)
        scanf("%d", &input[i]);

    struct SegTreeNode *root =  build_seg_tree(input, 0, size - 1);

    while(m--)
    {
        scanf("%d %d", &x, &y);
        get_max_and_freq(root, x-1 , y-1, &store_max, &store_freq);
        printf("%d\n", store_freq);
    }
    free(root);
    return 0;
}
