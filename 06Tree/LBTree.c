#include "LBTree.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\06Tree.LBTree.exe
// ab^^c^^
// abc
// abc
// bac
// bac
// bca
// bca
// abc
// abc
// 2
// 2
//
// Process finished with exit code 0

int main()
{
    LBTree tree = NULL;
    createLBTree(&tree);
    preOrderByRecursion(tree);
    printf("\n");
    preOrderByStack(tree);
    printf("\n");
    inOrderByRecursion(tree);
    printf("\n");
    inOrderByStack(tree);
    printf("\n");
    postOrderByRecursion(tree);
    printf("\n");
    postOrderByStack(tree);
    printf("\n");
    levelOrderByRecursion(tree);
    printf("\n");
    levelOrderByQueue(tree);
    printf("\n");
    printf("%d\n", getHeightByRecursion(tree));
    printf("%d\n", getHeightByQueue(tree));
    destroyLBTree(&tree);
    return 0;
}
