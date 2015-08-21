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

/*
    'build_seg_tree' function takes three arguements 
    1-> array of type int as first arguement
    2-> first index of the array
    3-> last index of the array
    
    after creating the segment tree 'build_seg_tree' returns the address of the root noe
*/

struct SegTreeNode* build_seg_tree(int *input,int low, int high);
void get_max_and_freq(struct SegTreeNode* root, int q_left, int q_right, int *store_max, int *store_freq);

#endif
