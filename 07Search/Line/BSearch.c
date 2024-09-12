#include <stdio.h>
#include <stdlib.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo比较一个移动一个，直到找到合适位置插入
// BinarySearh

typedef struct Node
{
    int* data;
    int length;
} Node;

typedef Node* List;

List toList(int data[], int length)
{
    List list = malloc(sizeof(Node));
    if (list != NULL)
    {
        list->data = (int*)malloc(length * sizeof(int));
        if (list->data == NULL)
        {
            free(list);
            return NULL;
        }
        for (int i = 0; i < length; i++)
        {
            list->data[i] = data[i];
        }
        list->length = length;
    }
    return list;
}

int searchData(List list, int data)
{
    if (list == NULL)
        return -1;
    int low = 0, high = list->length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (list->data[mid] < data)
            low = mid + 1;
        else if (list->data[mid] > data)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int data[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    List list = toList(data, 8);
    if (list != NULL)
    {
        printf("%d", searchData(list, 5));
        free(list->data);
        free(list);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
