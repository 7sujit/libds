#include "rb-tree.h"

struct Node *root_ptr;

int main(void)
{

    struct Node *root = NULL;
    root_ptr = NULL;
    long int loop;
    long int value;
    int ch;long int x;

    scanf("%ld",&loop );
    x = loop;
    while(loop --)
    {
        // ch = 1;
        scanf("%d %ld",&ch, &value );
        // scanf("%ld", &value);
        switch (ch) {
            case 0 :
                // (search(root, value)) ? printf("%s\n", "VALUE FOUND") : printf("%s\n", "VALUE NOT FOUND");
                break;
            case 1:
                rb_tr_insert( value);
                root = root_ptr;
                inorder(root);
                break;
            case 2:
                root = root_ptr;
                if(!root)
                {
                    printf("%s\n", "ROOT IS NULL");
                    break;
                }
                rb_tr_delete(value);
                root = root_ptr;
                inorder(root);
                break;
            case 3:
                root = root_ptr;
                // printf("rank of element %ld : %ld\n",value, rank(root, value));
                break;
            case 4:
                // root = root_ptr;
                // if(! root)
                //     break;
                // if(value > 1+root->lcount+root->rcount)
                // {
                //     printf("%s\n","EXCEEDS NUMBER OF ELEMENTS PRESENT IN TREE" );
                //     break;
                // }
                // printf("no at rank %ld : %ld\n",value, find_rank(root, value));
                break;
            default:
                break;
        }
    }
    printf("red nodes : %d\n", red_count(root_ptr));
    printf("root color : %s\n",(root_ptr->col)? "RED" : "BLACK" );
    printf("black nodes : %d\n", black_count(root_ptr));
    printf("lcount : %d, rcount = %d\n",root_ptr->lcount, root_ptr->rcount );

    // check_double_red(root_ptr);
    // black_path(root_ptr,0);
    // inorder(root_ptr);



    return EXIT_SUCCESS;
}
