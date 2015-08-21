#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef _MAXSEGTREE_H
#define _MAXSEGTREE_H

#define MAX(a,b) ((a) > (b) ? (a) : (b))



int segment_tree_size( int input_size );
void build_segment_tree(int *segment_tree, int *input, int low , int high, int pos);
int* get_segment_tree( int* input, int size );
int max_in_range(int* segment_tree,int low, int high, int q_left, int q_right, int pos);

void build_sum_segment_tree(int *segment_tree, int *input, int low , int high, int pos);
int* get_sum_segment_tree( int* input, int size );
int sum_in_range(int* segment_tree,int low, int high, int q_left, int q_right, int pos);


#endif
