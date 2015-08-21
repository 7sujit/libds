#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef _SEGTREE_H
#define _SEGTREE_H

#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct SegTreeNode
{
    int l_bound;
    int r_bound;
    int max_element;
    int freq_of_max;
    struct SegTreeNode *left_child,*right_child;
};

struct SegTreeNode* build_seg_tree(int *input,int low, int high);
void get_max_and_freq(struct SegTreeNode* root, int q_left, int q_right, int *store_max, int *store_freq);
// store_max is a pointer to the variable where we will be storing the max value
// store_freq is a pointer to the variable where we'll be storing the max value freq

#endif
