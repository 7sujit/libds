#include "rb-tree.h"

struct Node *root_ptr;

void check_double_red(struct Node *node)
{
	if(!node)
		return;

		check_double_red(node->left);

	if((node->left) && node->col == RED && node->left->col == RED)
		puts("double red");

	if((node->left) && node->col == RED && node->left->col == RED)
			puts("double red");

	check_double_red(node->right);

}

int red_count(struct Node *node)
{
	int count = 0;

	if(!node)
		return;

	count += red_count(node->left);
	if(node->col == RED)
		count += 1;
	count += red_count(node->right);

	return count;

}
int black_count(struct Node *node)
{
	int count = 0;

	if(!node)
		return;

	count += black_count(node->left);
	if(node->col == BLACK)
		count += 1;
	count += black_count(node->right);

	return count;

}


void rb_tr_insert(long int val)
{

	int uncle_col;
	struct Node *beta, *uncle;
	beta = tree_insert(val);

	while( (beta->p != NULL) && (beta->p->col == RED) )
	{
		// for left sub-tree

		if(beta->p == beta->p->p->left)
		{
			uncle = beta->p->p->right;
			(uncle)? (uncle_col = uncle->col)
						: (uncle_col = BLACK);

			if(uncle_col == RED)
			{
				uncle->col = beta->p->col = BLACK;
				beta->p->p->col = RED;
				beta = beta->p->p;
			}
			else // if uncle color is black or no uncle
			{
				if(beta == beta->p->right) // case - 2
					beta = left_rotate(beta->p, beta);
				else
					beta = beta->p;

				// case – 3

				beta = right_rotate(beta->p, beta);
				// beta->left->col = BLACK;
				beta->col = BLACK;
				beta->right->col = RED;
				break;
			}
		}

		// for right sub-tree
		else
		{
			uncle = beta->p->p->left;
			(uncle)? (uncle_col = uncle->col): (uncle_col = BLACK);

			if(uncle_col == RED)
			{
				uncle->col = beta->p->col = BLACK;
				beta->p->p->col = RED;
				beta = beta->p->p;
			}
			else // if uncle color is black or no uncle
			{
				if(beta == beta->p->left) // case - 2
					beta = right_rotate(beta->p, beta);
				else
					beta = beta->p;

				// case – 3
				beta = left_rotate(beta->p, beta);
				// beta->right->col = BLACK;
				beta->col = BLACK;
				beta->left->col = RED;
				break;
			}

		}
	}

	root_ptr->col = BLACK;

}

struct Node *create_node(long int val)
{
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    node->col = 1;
    node->lcount = node->rcount = 0;
    node->p = NULL;


    return node;
}

struct Node *tree_insert(long int val)
{
    struct Node *prev = NULL;
    struct Node *node;
    node = root_ptr;
    int diff;
    if(!node)
    {
        node = create_node(val);
        root_ptr = node;
        return node;
    }

    while(node)
    {
        if(val <= node->data)
        {
            ++(node->lcount);
            prev = node;
            node = node->left;
        }
        else
        {
            ++(node->rcount);
            prev = node;
            node = node->right;
        }
    }

    if(val <= prev->data)
    {
        prev->left = create_node(val);
        prev->left->p = prev;
        return prev->left;
    }
    else
    {
         prev->right = create_node(val);
         prev->right->p = prev;
         return prev->right;
     }

}



long int find_rank(struct Node *node, long int value)
{
    if( 1 + node->rcount == value)
        return node->data;
    else if(1 + node->rcount > value)
        return find_rank(node->right, value);
    else
        return find_rank(node->left, value - node->rcount - 1);
}

long int rank(struct Node *node, long int value)
{
    if(! node)
        return 1;

    if(node->data == value)
        return 1 + node->rcount;
    else if(value > node->data)
        return rank(node->right, value);
    else
        return 1 + node->rcount + rank(node->left, value);
}

struct Node *right_rotate(struct Node *alpha, struct Node *beta)
{
    if(!alpha)
        puts("alpha is nul");

    alpha->left = beta->right;

    if(beta->right)
        (beta->right->p = alpha);

    beta->p = alpha->p;

    if(! alpha->p)
        root_ptr = beta;
    else if(alpha->data < alpha->p->data)
        alpha->p->left = beta;
    else
        alpha->p->right = beta;

    beta->right = alpha;
    alpha->p = beta;


    update_count(alpha);
    update_count(beta);
    return beta;
}
struct Node *left_rotate(struct Node *alpha, struct Node *beta)
{

    alpha->right = beta->left;

    if(beta->left)
        (beta->left->p = alpha);

    beta->p = alpha->p;

    if(! alpha->p)
        root_ptr = beta;
    else if(alpha->data < alpha->p->data )
        alpha->p->left = beta;
    else
        alpha->p->right = beta;

// printf("root->data : %ld\n", root_ptr->data);

    beta->left = alpha;
    alpha->p = beta;


    update_count(alpha);
    update_count(beta);

    return beta;

}

void update_count(struct Node *node)
{
    (node->left)? (node->lcount = 1 + (node->left->lcount + node->left->rcount)) : (node->lcount = 0);
    (node->right)? (node->rcount = 1 + (node->right->lcount + node->right->rcount)) : (node->rcount = 0);
}

int search(struct Node *node, int val)
{
    while(node)
    {
        if(node->data == val)
            return 1;
        else if(val < node->data)
            node = node->left;
        else
            node = node->right;
    }

    return 0;
}

void inorder(struct Node* node)
{
    if(!node)
        return;

    inorder(node->left);
    printf("(<%d> %ld(%c) <%d>) ", node->lcount, node->data, (node->col)?'r':'b', node->rcount);
    // printf("%ld\n", rank(root_ptr,node->data));
    inorder(node->right);
}

void black_path(struct Node *node, int count)
{

	if(!node)
	{
		printf("%d\n", count);
		return;
	}


	if(node->col == BLACK)
		count += 1;

	black_path(node->left, count);
	black_path(node->right, count);

}

struct Node *locate(long int val)
{
    struct Node *node = root_ptr;
    while(node)
    {
        if(node->data == val)
            return node;
        else if(val > node->data )
            node = node->right;
        else
            node = node->left;
    }
    return node;
}




void rb_tr_delete(long int key)
{
    struct Node *child;
    struct Node *pred;
    struct Node *node = locate(key); // get location of the node to delete

    if(! node ) return;

    if(node->left != NULL && node->right != NULL)
    { // if node is of degree two copy the data from pred and delete pred

        pred = get_pred(node);
        
        node->data = pred->data;

        node = pred;    // now my target node is `pred` node
        
    }

    
    // since inorder pred can only have left child but no right child

    child = (node->right) ? (node->right) : (node->left);

    if( (node->col) == BLACK )
    {
        node->col = (child) ? (child->col) : (BLACK) ;
        delete_case1(node);
    }

    replace_node(node, child);

    if(node->p == NULL && child != NULL)
        child->col = BLACK;

    traceback(node);
    free(node);

}


void delete_case1(struct Node *node)
{

    if(node->p == NULL)
        return;
    else
        delete_case2(node);
}

void delete_case2(struct Node *node)
{

    struct Node *sibling = get_sibling(node);

    if(sibling->col == RED)
    {
        sibling->col = BLACK;
        node->p->col = RED;

        if(node == node->p->left)
            left_rotate(node->p, sibling);
        else
            right_rotate(node->p, sibling);

    }
    delete_case3(node);
}

void delete_case3(struct Node *node)
{ // p, sibling, and sibling's children are black

    struct Node *sibling = get_sibling(node);
    int sib_col = (sibling) ? sibling->col : BLACK;
    int sib_rc_col = (sibling->right)? sibling->right->col : BLACK;
    int sib_lc_col = (sibling->left)? sibling->left->col : BLACK;
    int par_col = (node->p)? node->p->col : BLACK;

    if( par_col == BLACK && sib_col == BLACK &&
        sib_lc_col == BLACK && sib_rc_col == BLACK  )
    {
        sibling->col = RED;
        delete_case1(node->p);

    }
    else
        delete_case4(node);
}

void delete_case4(struct Node *node)
{ // p is red but sibling, and sibling's children are black

    struct Node *sibling = get_sibling(node);
    int sib_col = (sibling) ? sibling->col : BLACK;
    int sib_rc_col = (sibling->right)? sibling->right->col : BLACK;
    int sib_lc_col = (sibling->left)? sibling->left->col : BLACK;
    int par_col = (node->p)? node->p->col : BLACK;

    if( par_col == RED && sib_col == BLACK &&
        sib_lc_col == BLACK && sib_rc_col == BLACK  )
    {
        sibling->col = RED;
        node->p->col = BLACK;
    }
    else
        delete_case5(node);

}

void delete_case5(struct Node *node)
{


    /*

        sub-cases :
        a)  if the node is the left child and sibling is black its left child is red and right child is black.

        b)  if the node is the right child and sibling is black its right child is red and left child is black.

        BOTH THE CASES ARE MIRROR IMAGE OF EACH OTHER

    */

    struct Node *sibling = get_sibling(node);
    int sib_col = (sibling) ? sibling->col : BLACK;
    int sib_rc_col = (sibling->right)? sibling->right->col : BLACK;
    int sib_lc_col = (sibling->left)? sibling->left->col : BLACK;
    int par_col = (node->p)? node->p->col : BLACK;


    if( node == node->p->left && sib_col == BLACK &&
        sib_lc_col == RED && sib_rc_col == BLACK    )
    {
        sibling->col = RED;
        if(sibling->left)
            sibling->left->col = BLACK;
        right_rotate(sibling, sibling->left);

    }
    else if(    node == node->p->right && sib_col == BLACK &&
            sib_lc_col == BLACK && sib_rc_col == RED    )
    {
        sibling->col = RED;
        if(sibling->right)
            sibling->right->col = BLACK;
        left_rotate(sibling, sibling->right);

    }

    delete_case6(node);

}


void delete_case6(struct Node *node)
{

    struct Node *sibling = get_sibling(node);

    sibling->col = (node->p) ? node->p->col : BLACK;
    node->p->col = BLACK;

    if(node == node->p->left)
    {
        if(sibling->right)
            sibling->right->col = BLACK;
        left_rotate(node->p, sibling);
    }
    else
    {
        if(sibling->left)
            sibling->left->col = BLACK;
        right_rotate(node->p, sibling);
    }

}

struct Node *get_pred(struct Node *node)
{
    struct Node *curr = node->left;

    while(curr->right)
        curr = curr->right;

    return curr;
}

void replace_node(struct Node *old, struct Node *new)
{
    if(old->p == NULL) // root node
    {
        root_ptr = new;
    }
    else
    {
        if(old == old->p->left)
            old->p->left = new;
        else
            old->p->right = new;
    }

    if(new)
    {
        new->p = old->p;
        new->lcount = old->lcount;
        new->rcount = old->rcount;
        update_count(new);
    }

}

struct Node *get_sibling(struct Node *node)
{
    if(node == node->p->left)
        return node->p->right;
    else
        return node->p->left;
}

void traceback(struct Node *node)
{
    while(node->p)
    {
        // puts("inside traceback");
        if(node->p->left == node)
        {   
            printf("lcou : %d", node->p->lcount);
            --(node->p->lcount);
            printf("lcou : %d\n", node->p->lcount);
        }
        // else
         {
             printf("lcou : %d", node->p->rcount);
            --(node->p->rcount);
            printf("lcou : %d\n", node->p->rcount);
         }  


        node = node->p;
    }
    printf("%s\n", "traceback");
    inorder(root_ptr);
    printf("\n");
}