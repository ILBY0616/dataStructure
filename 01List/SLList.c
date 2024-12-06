#include <SLList.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\01List.SLList.exe
// 5 4 3 2 1
// 1 2 3 4 5
// 1 2 3 4 5 6 7 8 9 10
// The 5 is in list
// 1 2 3 4 6 7 8 9 10
//
// Process finished with exit code 0

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
