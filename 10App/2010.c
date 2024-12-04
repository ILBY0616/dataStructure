#include <SStack.h>
#include <stdio.h>

// 设计编写顺序栈实现进制转换的程序
void baseConversion(SStack stack, int data)
{
    while (data > 0)
    {
        pushSStack(stack, data % 8);
        data /= 8;
    }
    while (stack->top != -1)
    {
        popSStack(stack, &data);
        printf("%d", data);
    }
}

// 编写双亲表示法存储哈夫曼树的创建、编码程序
// 见06Tree.SHTree.h中

// 编写邻接矩阵存储图的创建、广度优先遍历程序
// 见08Graph.AMGraph.h中

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\10App.2010.exe
// 12
// Process finished with exit code 0

int main()
{
    SStack stack;
    initiateSStack(&stack);
    baseConversion(stack, 10);
    destroySStack(&stack);
    return 0;
}
