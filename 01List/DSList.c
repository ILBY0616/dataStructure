#include <DSList.h>

int main()
{
    DSList list = NULL;
    initiateDSList(&list);
    for (int i = 0; i < 10; i++)
    {
        insertDSList(list, i, i + 1);
    }
    printDSList(list);
    printf("The 5 is at position %d\n", selectDSList(list, 5));
    deleteDSList(list, 4);
    printDSList(list);
    destroyDSList(&list);
    return 0;
}


