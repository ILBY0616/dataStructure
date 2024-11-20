#ifndef AMGRAPH_H
#define AMGRAPH_H

#include <stdlib.h>
#include <stdio.h>

// 邻接矩阵
typedef struct Graph
{
    char vertex[100];
    int edge[100][100];
    int vertexSum, edgeSum;
} Graph, *AMGraph;

// 开辟邻接矩阵
void initiateAMGraph(AMGraph* graph);
// 创建有向图
void createDAMGraph(AMGraph graph);
// 创建无向图
void createUAMGraph(AMGraph graph);
// 打印邻接矩阵
void printAMGraph(AMGraph graph);
// 销毁邻接矩阵
void destroyAMGraph(AMGraph* graph);

inline void initiateAMGraph(AMGraph* graph)
{
    while (*graph == NULL)
    {
        *graph = (AMGraph)malloc(sizeof(Graph));
    }
}

inline void createDAMGraph(AMGraph graph)
{
    printf("Input vertexSum edgeSum:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    // 初始化点
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("Input vertex %d's value:\n", i);
        getchar();
        scanf("%c", &graph->vertex[i]);
    }
    // 初始化边
    for (int i = 0; i < graph->vertexSum; i++)
    {
        for (int j = 0; j < graph->vertexSum; j++)
        {
            graph->edge[i][j] = 0;
        }
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        char startVertex, endVertex;
        printf("Input startVertex endVertex:\n");
        getchar();
        scanf("%c %c", &startVertex, &endVertex);
        //找到下标
        int startIndex = -1, endIndex = -1;
        for (int j = 0; j < graph->vertexSum; j++)
        {
            if (graph->vertex[j] == startVertex)
            {
                startIndex = j;
            }
            if (graph->vertex[j] == endVertex)
            {
                endIndex = j;
            }
        }
        // 标记为边
        if (startIndex != -1 && endIndex != -1)
        {
            graph->edge[startIndex][endIndex] = 1;
        }
        else
        {
            i--;
            printf("StartVertex and endVertex is invalid\n");
        }
    }
}

inline void createUAMGraph(AMGraph graph)
{
    printf("Input vertexSum edgeSum:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    // 初始化点
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("Input vertex %d's value:\n", i);
        getchar();
        scanf("%c", &graph->vertex[i]);
    }
    // 初始化边
    for (int i = 0; i < graph->vertexSum; i++)
    {
        for (int j = 0; j < graph->vertexSum; j++)
        {
            graph->edge[i][j] = 0;
        }
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        char startVertex, endVertex;
        printf("Input startVertex endVertex:\n");
        getchar();
        scanf("%c %c", &startVertex, &endVertex);
        //找到下标
        int startIndex = -1, endIndex = -1;
        for (int j = 0; j < graph->vertexSum; j++)
        {
            if (graph->vertex[j] == startVertex)
            {
                startIndex = j;
            }
            if (graph->vertex[j] == endVertex)
            {
                endIndex = j;
            }
        }
        // 标记为边
        if (startIndex != -1 && endIndex != -1)
        {
            graph->edge[startIndex][endIndex] = 1;
            graph->edge[endIndex][startIndex] = 1;
        }
        else
        {
            i--;
            printf("StartVertex and endVertex is invalid\n");
        }
    }
}

inline void printAMGraph(AMGraph graph)
{
    printf("AMGraph:\n");
    for (int i = 0; i < graph->vertexSum; i++)
    {
        for (int j = 0; j < graph->vertexSum; j++)
        {
            printf("%d ", graph->edge[i][j]);
        }
        printf("\n");
    }
}

inline void destroyAMGraph(AMGraph* graph)
{
    free(*graph);
    *graph = NULL;
}

#endif
