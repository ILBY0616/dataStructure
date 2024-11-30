#ifndef AMGRAPH_H
#define AMGRAPH_H

#include <stdbool.h>
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
bool initiateAMGraph(AMGraph* graph);
// 创建有向图
void createDAMGraph(AMGraph graph);
// 创建无向图
void createUAMGraph(AMGraph graph);
// 判断边存在
bool judgeEdgeAMGraph(AMGraph graph, int startIndex, int endIndex);
// 深度优先遍历
void DFSAMGraph(AMGraph graph, int startIndex,bool visited[]);
// 广度优先遍历
void BFSAMGraph(AMGraph graph, int startIndex,bool visited[]);
// 打印邻接矩阵
void printAMGraph(AMGraph graph);
// 销毁邻接矩阵
void destroyAMGraph(AMGraph* graph);

inline bool initiateAMGraph(AMGraph* graph)
{
    if (*graph != NULL)
    {
        return false;
    }
    *graph = (AMGraph)malloc(sizeof(Graph));
    if (*graph == NULL)
    {
        return false;
    }
    return true;
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
            if (i == j)
            {
                graph->edge[i][j] = 0;
            }
            else
            {
                graph->edge[i][j] = INT_MAX;
            }
        }
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        int weight, startIndex, endIndex;
        printf("Input weight startIndex endIndex:\n");
        scanf("%d %d %d", &weight, &startIndex, &endIndex);
        // 无边 weight is INT_MAX
        // 有边 weight in [0,INT_MAX-1]
        if (
            0 <= weight && weight < INT_MAX &&
            0 <= startIndex && startIndex < graph->vertexSum &&
            0 <= endIndex && endIndex < graph->vertexSum
        )
        {
            graph->edge[startIndex][endIndex] = weight;
        }
        else
        {
            i--;
            printf("StartIndex and endIndex is invalid\n");
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
            if (i == j)
            {
                graph->edge[i][j] = 0;
            }
            else
            {
                graph->edge[i][j] = INT_MAX;
            }
        }
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        int weight, startIndex, endIndex;
        printf("Input weight startIndex endIndex:\n");
        scanf("%d %d %d", &weight, &startIndex, &endIndex);
        // 无边 weight is INT_MAX
        // 有边 weight in [0,INT_MAX-1]
        if (
            0 <= weight && weight < INT_MAX &&
            0 <= startIndex && startIndex < graph->vertexSum &&
            0 <= endIndex && endIndex < graph->vertexSum
        )
        {
            graph->edge[startIndex][endIndex] = weight;
            graph->edge[endIndex][startIndex] = weight;
        }
        else
        {
            i--;
            printf("StartIndex and endIndex is invalid\n");
        }
    }
}

inline bool judgeEdgeAMGraph(AMGraph graph, int startIndex, int endIndex)
{
    if (
        graph->vertexSum <= startIndex || startIndex < 0 ||
        graph->vertexSum <= endIndex || endIndex < 0 ||
        INT_MAX <= graph->edge[startIndex][endIndex] || graph->edge[startIndex][endIndex] < 0
    )
    {
        return false;
    }
    return true;
}

inline void DFSAMGraph(AMGraph graph, int startIndex,bool visited[])
{
    visited[startIndex] = true;
    printf("%c", graph->vertex[startIndex]);
    for (int i = 0; i < graph->vertexSum; i++)
    {
        if (judgeEdgeAMGraph(graph, startIndex, i) == true && visited[i] == false)
        {
            DFSAMGraph(graph, i, visited);
        }
    }
}

inline void BFSAMGraph(AMGraph graph, int startIndex,bool visited[])
{
    int front = -1, rear = -1;
    int queue[graph->vertexSum];
    queue[++rear] = startIndex;
    visited[startIndex] = true;
    while (front < rear)
    {
        int index = queue[++front];
        printf("%c", graph->vertex[index]);
        for (int i = 0; i < graph->vertexSum; i++)
        {
            if (judgeEdgeAMGraph(graph, index, i) && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
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
