#include <SStack.h>
#include <stdio.h>

// 十进制正整数化为八进制正整数
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

// 根据字符数组创建哈夫曼树并且输出其哈夫曼编码
// 见SHTree.h中

// 用邻接矩阵存储、深度优先遍历图
// 见AMGraph.h中

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
