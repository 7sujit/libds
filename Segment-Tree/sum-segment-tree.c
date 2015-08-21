#include "maxsegtree.h"


void build_sum_segment_tree(int *segment_tree, int *input, int low , int high, int pos)
{// builds the segment_tree from the input array
    int mid;
    if(low == high)
    {
        segment_tree[pos] = input[low];
        return;
    }

    mid = (low + high) / 2;

    build_sum_segment_tree(segment_tree, input, low, mid, (2*pos + 1) );
    build_sum_segment_tree(segment_tree, input, mid + 1, high, (2*pos + 2) );

    segment_tree[pos] = ( segment_tree[2*pos + 1] + segment_tree[2*pos + 2] );
}


int* get_sum_segment_tree( int* input, int size )
{// returns to the pointer to the segment_tree array after building the tree

    int *segment_tree = (int *) calloc (segment_tree_size(size), sizeof(int));

    puts("calling sum segment");
    build_sum_segment_tree(segment_tree, input, 0, size - 1, 0);

    return segment_tree;
}


int sum_in_range(int* segment_tree,int low, int high, int q_left, int q_right, int pos)
{
    int l_range = 2 * pos + 1;
    int r_range = l_range + 1;

    int mid = (low + high) / 2;

    if(low > high || q_left > high || q_right < low )// no overlap condition
        return 0;

    else if( q_left <= low && high <= q_right)// total overlap condition
        return segment_tree[pos];


    // partial overlap
    return (sum_in_range(segment_tree, low, mid, q_left, q_right, l_range) +
                     sum_in_range(segment_tree,mid+1, high, q_left, q_right, r_range));
}
