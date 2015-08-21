#include "segtree.h"

/*
struct SegTreeNode
{
    int l_bound;
    int r_bound;
    int max_element;
    int freq_of_max;
    SegTreeNode *left_child,*right_child;

};

code for updation of any node is yet to be done

*/


struct SegTreeNode* build_seg_tree(int *input, int low, int high)
{// returns address of the root of the seg_tree
    int mid;
    struct SegTreeNode* segNode = (struct SegTreeNode*)malloc(sizeof(struct SegTreeNode));

    if(low == high)
    {
        segNode->l_bound = low;
        segNode->r_bound = high;
        segNode->max_element = input[low];
        segNode->freq_of_max = 1;
        segNode->left_child = NULL;
        segNode->right_child = NULL;

        return segNode;
    }

    mid = (low + high) / 2;

    segNode->left_child = build_seg_tree(input, low, mid);
    segNode->right_child = build_seg_tree(input, mid + 1, high);

    if(segNode->left_child->max_element > segNode->right_child->max_element )
    {
        segNode->max_element = segNode->left_child->max_element;
        segNode->freq_of_max = segNode->left_child->freq_of_max;
    }
    else if(segNode->left_child->max_element < segNode->right_child->max_element)
    {
        segNode->max_element = segNode->right_child->max_element;
        segNode->freq_of_max = segNode->right_child->freq_of_max;
    }
    else // if equal
    {
        segNode->max_element = segNode->left_child->max_element;
        segNode->freq_of_max = segNode->left_child->freq_of_max + segNode->right_child->freq_of_max;
    }

    segNode->l_bound = low;
    segNode->r_bound = high;

    return segNode;
}


void get_max_and_freq(struct SegTreeNode* root, int q_left, int q_right, int *store_max, int *store_freq)
{
    int max_left,max_right;
    int max_left_freq, max_right_freq;

    if(!root)
    {

        *store_max = INT_MIN;
        *store_freq = INT_MIN;
        return;
    }

    if(q_left > q_right || q_right < root->l_bound || q_left > root->r_bound ) // no overlap
    {
        *store_max = INT_MIN;
        *store_freq = INT_MIN;
        return;
    }
    else if ( q_left <= root->l_bound &&  root->r_bound <= q_right) // total overlap
    {
        *store_max = root->max_element;
        *store_freq = root->freq_of_max;
        return;
    }

    get_max_and_freq(root->left_child, q_left, q_right,&max_left, &max_left_freq);
    get_max_and_freq(root->right_child, q_left, q_right,&max_right, &max_right_freq);

    if(max_left > max_right)
    {
        *store_max = max_left;
        *store_freq = max_left_freq;
    }
    else if( max_right > max_left)
    {
        *store_max = max_right;
        *store_freq = max_right_freq;
    }
    else
    {
        *store_max = max_left;
        *store_freq = (max_right_freq + max_left_freq);
    }

    return;
}
