#include <SSList.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\01List.SSList.exe
// 1 2 3 4 5 6 7 8 9 10
// The 5 is at position 4
// 1 2 3 4 6 7 8 9 10
//
// Process finished with exit code 0

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
