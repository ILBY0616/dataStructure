#include <LBTree.h>

// 统计链式二叉树结点数
int getNodeSum(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return getNodeSum(tree->left) + getNodeSum(tree->right) + 1;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2008.exe
// ab^^c^^
// 3
// Process finished with exit code 0

int main()
{
    LBTree tree = NULL;
    buildLBTree(&tree);
    printf("%d", getNodeSum(tree));
    destroyLBTree(&tree);
    return 0;
}
