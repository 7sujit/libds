#include "maxsegtree.h"

int main(void)
{

    int a[] = {1 ,2 ,3 };
    int size = sizeof(a) /  sizeof(int);
    int *new_tree = NULL;
    int i,flag = 0;

    printf("Input array : \n");
    for(i = 0; i < (size); ++i)
        printf("%d ", a[i]);

    new_tree = get_sum_segment_tree(a, size);

    printf("Sum Segment Tree array : \n" );
    for(i = 0; i < segment_tree_size(size); ++i)
        printf("%d ", new_tree[i]);

    printf("\nFinding sum between index range (2,4) : %d\n", sum_in_range(new_tree,0,size - 1,2,4,0));
    printf("Finding sum between index range (6,6) : %d\n", sum_in_range(new_tree,0,size - 1,6,6,0));

    for ( i = 1; i+1 < size; i++) {
        if(sum_in_range(new_tree,0, size-1, 0, i-1, 0) ==
                sum_in_range(new_tree,0, size-1, i + 1, size - 1, 0))
        {
            flag = 1;
        }
    }

    if(flag)
        puts("YES");
    else
        puts("NO");

    free(new_tree);
    return EXIT_SUCCESS;
}
