#include <LBTree.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\06Tree.LBTree.exe
// abd^^e^^cf^^g^^
// abdecfg
// dbeafcg
// debfgca
// abcdefg
// 3
// 4
//
// Process finished with exit code 0

int main()
{
    LBTree tree = NULL;
    buildLBTree(&tree);
    preOrderLBTree(tree);
    printf("\n");
    inOrderLBTree(tree);
    printf("\n");
    postOrderLBTree(tree);
    printf("\n");
    levelOrderLBTree(tree);
    printf("\n");
    printf("%d\n", getHeightLBTree(tree));
    printf("%d\n", getWidthLBTree(tree));
    destroyLBTree(&tree);
    return 0;
}
