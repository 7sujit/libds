#include "ufind.h"

UFindNode *uset;


int main(void)
{
    int x,y,z;
    int size,test;
    scanf("%d %d", &size, &test);
    create_ufind_ds(size);

    while(test --)
    {
        scanf("%d",&x);

        switch (x)
        {
            case 1:
                scanf("%d %d",&y, &z );
                if(!same_set(y,z))
                    make_union(y,z);
                else
                    puts("same set");
                break;

            case 2:
                scanf("%d %d",&y, &z );
                if(same_set(y,z))
                    puts("same set");
                else
                    puts("not in same set");

                break;

            case 3:
                scanf("%d", &y);
                printf("(%d) is in set %d\n", y, find(y));
                break;

            default:
                break;
        }
    }

    print_ds(size);


    return EXIT_SUCCESS;
}
