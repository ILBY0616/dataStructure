#include <LBTree.h>

// 递归统计链二叉树结点数
void getTotal(LBTree tree, int* total)
{
    if (tree != NULL)
    {
        (*total)++;
        getTotal(tree->left, total);
        getTotal(tree->right, total);
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2008.exe
// ab^^c^^
// 3
//
// Process finished with exit code 0

int main()
{
    int total = 0;
    LBTree tree = NULL;
    buildLBTree(&tree);
    getTotal(tree, &total);
    printf("%d\n", total);
    destroyLBTree(&tree);
    return 0;
}
