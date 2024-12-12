#include <stdlib.h>
#include <stdio.h>

#define size  10
#define length  100

typedef struct HashNode
{
    int data;
    struct HashNode* next;
}* HashNode;

int hashValue(int key)
{
    return key % size;
}

void buildTable(HashNode* hashTable, int* data)
{
    for (int i = 0; i < size; i++)
    {
        hashTable[i] = NULL;
    }
    for (int i = 0; i < length; i++)
    {
        HashNode node = malloc(sizeof(struct HashNode));
        if (node != NULL)
        {
            int index = hashValue(data[i]);
            node->data = data[i];
            node->next = hashTable[index];
            hashTable[index] = node;
        }
    }
}

int hashSearch(HashNode* hashTable, int key)
{
    int index = hashValue(key);
    HashNode node = hashTable[index];
    while (node != NULL)
    {
        if (node->data == key)
        {
            return index;
        }
        node = node->next;
    }
    return -1;
}

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\08Search.HashSearch.exe
// 5
// 进程已结束，退出代码为 0

int main()
{
    int data[100] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
        58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
        86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
    };
    int key = 5;
    HashNode hashTable[size];
    buildTable(hashTable, data);
    printf("%d", hashSearch(hashTable, key));
    return 0;
}
