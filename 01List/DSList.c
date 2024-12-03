#include <DSList.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\01List.DSList.exe
// 1 2 3 4 5 6 7 8 9 10
// The 5 is at position 4
// 1 2 3 4 6 7 8 9 10
//
// Process finished with exit code 0

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


