#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _H_RBTREE
#define _H_RBTREE

#define MAX(a,b) (((a)>(b))?(a):(b))

#define RED 1
#define BLACK 0

struct Node
{
        long int data;
        struct Node *left, *right;
        struct Node *p;
        int lcount, rcount;
        int col;
};

void black_path(struct Node *node, int count);
void check_double_red(struct Node *node);
void rb_tr_insert(long int val);
struct Node *tree_insert(long int value);

long int find_rank(struct Node *node, long int rank);
long int rank(struct Node *node, long int value);

struct Node *left_rotate(struct Node *alpha, struct Node *beta);
struct Node *right_rotate(struct Node *alpha, struct Node *beta);

int search(struct Node *node, int val);
void update_count(struct Node *node);
void inorder(struct Node* node);
int red_count(struct Node *node);
int black_count(struct Node *node);

void rb_tr_delete(long int key);
void delete_case1(struct Node *node);
void delete_case2(struct Node *node);
void delete_case3(struct Node *node);
void delete_case4(struct Node *node);
void delete_case5(struct Node *node);
void delete_case6(struct Node *node);

struct Node *locate(long int val);
struct Node *get_sibling(struct Node *node);
struct Node *get_pred(struct Node *node);
void replace_node(struct Node *old, struct Node *new);
void traceback(struct Node *node);

#endif
