#include <stdio.h>
#include <stdlib.h>

#define newSize 10
#define type int

// 统一重点：ToDo
// 统一提示：提示需要中文
// 统一注释：注释在代码上方
// 统一状态：-1失败，0成功，1其他

// 动态顺序表
typedef struct
{
    type* data;
    int size, length;
} DSList;

// 初始化线性表
void initiateList(DSList* l)
{
    l->data = (type*)malloc(newSize * sizeof(type));
    l->size = newSize;
    l->length = 0;
}

// 删除所有minData与maxData之间的数，要求时间复杂度O(n)，空间复杂度O(1)
int jop04(DSList* l, type minData,type maxData)
{
    if (minData >= maxData || l->length == 0)
    {
        return -1;
    }
    int step = 0;
    for (int i = 0; i < l->length; i++)
    {
        if (minData <= l->data[i] && l->data[i] <= maxData)
        {
            step++;
        }
        else
        {
            l->data[i - step] = l->data[i];
        }
    }
    l->length -= step;
    return 0;
}

int main()
{
    system("chcp 65001");
    DSList l;
    initiateList(&l);
    printf("当前数组元素：");
    for (int i = 0; i < l.size; i++)
    {
        // 填充一些重复的值
        l.data[i] = i % 3;
        printf("%d ", l.data[i]);
        l.length++;
    }
    printf("\n");

    // 删除所有值为0-1的元素
    jop04(&l, 1, 2);

    printf("当前数组元素：");
    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }
    printf("\n");

    free(l.data);
    return 0;
}
