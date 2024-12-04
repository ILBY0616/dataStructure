#include <LBTree.h>

// 编写邻接表存储图的定义、创建程序
// 见08Graph.ATGraph.h中

// 编写三元数组存储稀疏矩阵的定义、转置程序
// 见04Array.SMatrix.h中

// 统计链式二叉树结点数
void getNodeSum(LBTree tree, int* sum)
{
    if (tree != NULL)
    {
        (*sum)++;
        getNodeSum(tree->left, sum);
        getNodeSum(tree->right, sum);
    }
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2008.exe
// ab^^c^^
// 3
// Process finished with exit code 0

int main()
{
    int sum = 0;
    LBTree tree = NULL;
    buildLBTree(&tree);
    getNodeSum(tree, &sum);
    printf("%d", sum);
    destroyLBTree(&tree);
    return 0;
}
