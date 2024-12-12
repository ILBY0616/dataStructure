#include <stdio.h>

#define size 10
#define length 100
#define collision 5

typedef struct HashNode
{
    int data;
    int flag;
} HashNode;

int hashOne(int key)
{
    return key % size;
}

int hashTow(int key)
{
    return 7 - (key % 7);
}

int hashThree(int key)
{
    return 13 - (key % 13);
}

void buildTable(HashNode* hashTable, int* data)
{
    for (int i = 0; i < size; i++)
    {
        hashTable[i].flag = 0;
    }
    for (int i = 0; i < length; i++)
    {
        int index, hashValue = hashOne(data[i]);
        int nextHashValue = 0;
        for (int j = 0; j < collision; j++)
        {
            switch (nextHashValue)
            {
            case 0: index = (hashValue + j * hashTow(data[i])) % size;
                break;
            case 1: index = (hashValue + j * hashThree(data[i])) % size;
                break;
            default: index = (hashValue + j) % size;
                break;
            }
            if (hashTable[index].flag != 1)
            {
                hashTable[index].data = data[i];
                hashTable[index].flag = 1;
                break;
            }
            nextHashValue = (nextHashValue + 1) % 3;
        }
    }
}

int hashSearch(HashNode* hashTable, int key)
{
    int h1 = hashOne(key);
    int hashFunc = 0;

    for (int j = 0; j < collision; j++)
    {
        int index;
        switch (hashFunc)
        {
        case 0: index = (h1 + j * hashTow(key)) % size;
            break;
        case 1: index = (h1 + j * hashThree(key)) % size;
            break;
        default: index = (h1 + j) % size;
            break;
        }

        if (hashTable[index].flag == 0)
        {
            return -1; // 查找失败
        }

        if (hashTable[index].flag == 1 && hashTable[index].data == key)
        {
            return index; // 找到
        }

        // 切换哈希函数
        hashFunc = (hashFunc + 1) % 3;
    }

    return -1;
}

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
