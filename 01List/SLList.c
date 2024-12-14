#include <SLList.h>

int main()
{
    SLList list = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    buildSLListByHead(data, 5, &list);
    printSLList(list);
    destroySLList(&list);
    buildSLListByTail(data, 5, &list);
    printSLList(list);
    destroySLList(&list);
    initiateSLList(&list);
    for (int i = 0; i < 10; i++)
    {
        insertSLList(list, i, i + 1);
    }
    printSLList(list);
    printf("The %d is in list\n", selectSLList(list, 5)->data);
    deleteSLList(list, 4);
    printSLList(list);
    destroySLList(&list);
    return 0;
}
