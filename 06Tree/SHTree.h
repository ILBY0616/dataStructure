#ifndef SHTREE_H
#define SHTREE_H

#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

// 顺序哈夫曼树结点
typedef struct SHTreeNode
{
    char data;
    int up, left, right, weight;
}* SHTree;

// 初始顺序哈夫曼树
bool initiateSHTree(SHTree* tree, int length);
// 建造顺序哈夫曼树
bool buildSHTree(SHTree* tree, int length);
// 编码顺序哈夫曼树
bool buildSHTreeCode(SHTree* tree, int length);
// 销毁顺序哈夫曼树
bool destroySHTree(SHTree* tree);

inline bool initiateSHTree(SHTree* tree, int length)
{
    if (*tree != NULL || length < 1)
    {
        return false;
    }
    *tree = (SHTree)malloc(2 * length * sizeof(struct SHTreeNode));
    if (*tree == NULL)
    {
        return false;
    }
    for (int i = 0; i < 2 * length; i++)
    {
        (*tree)[i].data = '\n';
        (*tree)[i].up = (*tree)[i].left = (*tree)[i].right = (*tree)[i].weight = -1;
    }
    char data;
    int weight;
    for (int i = 0; i < length; i++)
    {
        scanf("%c%d", &data, &weight);
        if ('a' <= data && data <= 'z' && -1 < weight && weight < INT_MAX)
        {
            (*tree)[i].data = data;
            (*tree)[i].weight = weight;
        }
        else
        {
            i--;
            printf("Data or weight is invalid");
        }
    }
    return true;
}

inline bool buildSHTree(SHTree* tree, int length)
{
    if (*tree == NULL || length < 1)
    {
        return false;
    }
    for (int i = length; i < 2 * length - 1; i++)
    {
        int lChild = -1, rChild = -1, lWeight = INT_MAX, rWeight = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if ((*tree)[j].weight < lWeight && (*tree)[j].up == -1)
            {
                rWeight = lWeight;
                lWeight = (*tree)[j].weight;
                rChild = lChild;
                lChild = j;
            }
            else if ((*tree)[j].weight < rWeight && (*tree)[j].up == -1)
            {
                rWeight = (*tree)[j].weight;
                rChild = j;
            }
        }
        (*tree)[lChild].up = (*tree)[rChild].up = i;
        (*tree)[i].left = lChild;
        (*tree)[i].right = rChild;
        (*tree)[i].weight = (*tree)[rChild].weight + (*tree)[lChild].weight;
    }
    return true;
}

inline bool buildSHTreeCode(SHTree* tree, int length)
{
    if (*tree == NULL || length < 1)
    {
        return false;
    }
    char code[length];
    for (int i = 0; i < length; i++)
    {
        int current = i, index = 0;
        while ((*tree)[current].up != -1)
        {
            if ((*tree)[(*tree)[current].up].left == current)
            {
                code[index++] = '0';
            }
            else
            {
                code[index++] = '1';
            }
            current = (*tree)[current].up;
        }
        code[index] = '\0';
        for (int j = 0; j < index / 2; j++)
        {
            char temp = code[j];
            code[j] = code[index - j - 1];
            code[index - j - 1] = temp;
        }
        printf("%c: %s\n", (*tree)[i].data, code);
    }
    return true;
}

inline bool destroySHTree(SHTree* tree)
{
    if (*tree == NULL)
    {
        return false;
    }
    free(*tree);
    *tree = NULL;
    return true;
}

#endif
