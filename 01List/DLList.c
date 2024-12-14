#include <DLList.h>

int main()
{
    DLList list = NULL;
    int data[5] = {1, 2, 3, 4, 5};
    buildDLListByHead(data, 5, &list);
    printDLList(list);
    destroyDLList(&list);
    buildDLListByTail(data, 5, &list);
    printDLList(list);
    destroyDLList(&list);
    initiateDLList(&list);
    for (int i = 0; i < 10; i++)
    {
        insertDLList(list, i, i + 1);
    }
    printDLList(list);
    printf("The %d is in list\n", selectDLList(list, 5)->data);
    deleteDLList(list, 4);
    printDLList(list);
    destroyDLList(&list);
    return 0;
}
