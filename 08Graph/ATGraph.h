#ifndef ATGRAPH_H
#define ATGRAPH_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

// 边
typedef struct Edge
{
    int index;
    int weight;
    struct Edge* next;
} Edge;

// 点
typedef struct Vertex
{
    char data;
    Edge* first;
} Vertex;

// 邻接表
typedef struct Graph
{
    Vertex vertex[100];
    int vertexSum, edgeSum;
} Graph, *ATGraph;

// 开辟邻接表
bool initiateATGraph(ATGraph* graph);
// 创建有向图
void createDATGraph(ATGraph graph);
// 创建无向图
void createUATGraph(ATGraph graph);
// 判断边存在
bool judgeEdgeATGraph(ATGraph graph, int startIndex, int endIndex);
// 深度优先遍历
bool DFSATGraph(ATGraph graph, int startIndex,bool* visited);
// 广度优先遍历
bool BFSATGraph(ATGraph graph, int startIndex,bool* visited);
// 打印邻接表
void printATGraph(ATGraph graph);
// 销毁邻接表
void destroyATGraph(ATGraph* graph);

inline bool initiateATGraph(ATGraph* graph)
{
    if (*graph != NULL)
    {
        return false;
    }
    *graph = (ATGraph)malloc(sizeof(Graph));
    if (*graph == NULL)
    {
        return false;
    }
    return true;
}

inline void createDATGraph(ATGraph graph)
{
    printf("Input vertexSum edgeSum:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    // 初始化点
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("Input vertex %d's value:\n", i);
        scanf(" %c", &graph->vertex[i].data);
        graph->vertex[i].first = NULL;
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        int weight, startIndex, endIndex;
        printf("Input startIndex endIndex weight:\n");
        scanf("%d %d %d", &startIndex, &endIndex, &weight);
        // 无边 edge is NULL
        // 有边 weight in [1,INT_MAX-1]
        if (
            0 <= startIndex && startIndex < graph->vertexSum &&
            0 <= endIndex && endIndex < graph->vertexSum &&
            0 < weight && weight < INT_MAX
        )
        {
            Edge* edge = malloc(sizeof(Edge));
            if (edge != NULL)
            {
                edge->index = endIndex;
                edge->weight = weight;
                edge->next = graph->vertex[startIndex].first;
                graph->vertex[startIndex].first = edge;
            }
            else
            {
                free(edge);
                i--;
            }
        }
        else
        {
            i--;
            printf("StartIndex or endIndex or weight is invalid\n");
        }
    }
}

inline void createUATGraph(ATGraph graph)
{
    printf("Input vertexSum edgeSum:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    // 初始化点
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("Input vertex %d's value:\n", i);
        scanf(" %c", &graph->vertex[i].data);
        graph->vertex[i].first = NULL;
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        int weight, startIndex, endIndex;
        printf("Input startIndex endIndex weight:\n");
        scanf("%d %d %d", &startIndex, &endIndex, &weight);
        // 无边 edge is NULL
        // 有边 weight in [1,INT_MAX-1]
        if (
            0 <= startIndex && startIndex < graph->vertexSum &&
            0 <= endIndex && endIndex < graph->vertexSum &&
            0 < weight && weight < INT_MAX
        )
        {
            Edge* edgeOne = malloc(sizeof(Edge));
            Edge* edgeTwo = malloc(sizeof(Edge));
            if (edgeOne != NULL && edgeTwo != NULL)
            {
                edgeOne->index = endIndex;
                edgeOne->weight = weight;
                edgeOne->next = graph->vertex[startIndex].first;
                graph->vertex[startIndex].first = edgeOne;
                edgeTwo->index = startIndex;
                edgeTwo->weight = weight;
                edgeTwo->next = graph->vertex[endIndex].first;
                graph->vertex[endIndex].first = edgeTwo;
            }
            else
            {
                free(edgeOne);
                free(edgeTwo);
                i--;
            }
        }
        else
        {
            i--;
            printf("StartIndex or endIndex or weight is invalid\n");
        }
    }
}

inline bool judgeEdgeATGraph(ATGraph graph, int startIndex, int endIndex)
{
    if (
        graph->vertexSum <= startIndex || startIndex < 0 ||
        graph->vertexSum <= endIndex || endIndex < 0
    )
    {
        return false;
    }
    Edge* edge = graph->vertex[startIndex].first;
    while (edge != NULL)
    {
        if (edge->index == endIndex)
        {
            return true;
        }
        edge = edge->next;
    }
    return false;
}

inline bool DFSATGraph(ATGraph graph, int startIndex,bool* visited)
{
    if (graph->vertexSum <= startIndex || startIndex < 0)
    {
        return false;
    }
    visited[startIndex] = true;
    printf("%c", graph->vertex[startIndex].data);
    Edge* edge = graph->vertex[startIndex].first;
    while (edge != NULL)
    {
        if (visited[edge->index] == false)
        {
            DFSATGraph(graph, edge->index, visited);
        }
        edge = edge->next;
    }
    return true;
}

inline bool BFSATGraph(ATGraph graph, int startIndex,bool* visited)
{
    if (graph->vertexSum <= startIndex || startIndex < 0)
    {
        return false;
    }
    int front = -1, rear = -1;
    int queue[graph->vertexSum];
    queue[++rear] = startIndex;
    visited[startIndex] = true;
    while (front < rear)
    {
        int currentIndex = queue[++front];
        printf("%c", graph->vertex[currentIndex].data);
        Edge* edge = graph->vertex[currentIndex].first;
        while (edge != NULL)
        {
            if (!visited[edge->index])
            {
                queue[++rear] = edge->index;
                visited[edge->index] = true;
            }
            edge = edge->next;
        }
    }
    return true;
}

inline void printATGraph(ATGraph graph)
{
    printf("ATGraph:\n");
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("%c", graph->vertex[i].data);
        Edge* edge = graph->vertex[i].first;
        while (edge != NULL)
        {
            printf("->%d", edge->index);
            edge = edge->next;
        }
        printf("\n");
    }
}

inline void destroyATGraph(ATGraph* graph)
{
    for (int i = 0; i < (*graph)->vertexSum; i++)
    {
        Edge* edge = (*graph)->vertex[i].first;
        while (edge != NULL)
        {
            Edge* node = edge;
            edge = edge->next;
            free(node);
        }
        (*graph)->vertex[i].first = NULL;
    }
    free(*graph);
    *graph = NULL;
}

#endif
