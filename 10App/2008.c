#include <LBTree.h>

// 用邻接表存储、创建、打印无向图
// 见ATGraph.h中void createDATGraph(ATGraph graph);void printATGraph(ATGraph graph);

// 用三元数组存储、装置稀疏矩阵
// 见SMartrix.h中SMatrix transposeSMatrix(SMatrix matrix);

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
