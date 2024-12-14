#include <SSList.h>

int main()
{
    SSList list = NULL;
    initiateSSList(&list);
    for (int i = 0; i < 10; i++)
    {
        insertSSList(list, i, i + 1);
    }
    printSSList(list);
    printf("The 5 is at position %d\n", selectSSList(list, 5));
    deleteSSList(list, 4);
    printSSList(list);
    destroySSList(&list);
    return 0;
}
