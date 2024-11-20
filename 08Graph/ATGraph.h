#ifndef ATGRAPH_H
#define ATGRAPH_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 边
typedef struct Edge
{
    char data;
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
void initiateATGraph(ATGraph* graph);
// 创建有向图
void createDATGraph(ATGraph graph);
// 创建无向图
void createUATGraph(ATGraph graph);
// 打印邻接表
void printATGraph(ATGraph graph);
// 销毁邻接表
void destroyATGraph(ATGraph* graph);

inline void initiateATGraph(ATGraph* graph)
{
    while (*graph == NULL)
    {
        *graph = (ATGraph)malloc(sizeof(Graph));
    }
}

inline void createDATGraph(ATGraph graph)
{
    printf("Input vertexSum edgeSum:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);
    // 初始化点
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("Input vertex %d's value:\n", i);
        getchar();
        scanf("%c", &graph->vertex[i].data);
        graph->vertex[i].first = NULL;
    }
    // 建立起边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        int startIndex, endIndex;
        printf("Input startIndex endIndex:\n");
        scanf("%d %d", &startIndex, &endIndex);
        // 检查重边
        Edge* current = graph->vertex[startIndex].first;
        bool edgeExist = false;
        while (current != NULL)
        {
            if (current->data == graph->vertex[endIndex].data)
            {
                edgeExist = true;
                break;
            }
            current = current->next;
        }
        if (edgeExist == true)
        {
            printf("StartIndex and endIndex is invalid:\n");
        }
        else
        {
            Edge* edge = malloc(sizeof(Edge));
            if (edge != NULL)
            {
                edge->data = graph->vertex[endIndex].data;
                edge->next = graph->vertex[startIndex].first;
                graph->vertex[startIndex].first = edge;
            }
            else
            {
                free(edge);
                i--;
            }
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
        getchar();
        scanf("%c", &graph->vertex[i].data);
        graph->vertex[i].first = NULL;
    }
    // 初始化边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        int startIndex, endIndex;
        printf("Input startIndex endIndex:\n");
        getchar();
        scanf("%d %d", &startIndex, &endIndex);
        // 检查重边
        Edge* current = graph->vertex[startIndex].first;
        bool edgeExist = false;
        while (current != NULL)
        {
            if (current->data == graph->vertex[endIndex].data)
            {
                edgeExist = true;
                break;
            }
            current = current->next;
        }
        if (edgeExist == true)
        {
            printf("StartIndex and endIndex is invalid:\n");
        }
        else
        {
            Edge* edgeOne = malloc(sizeof(Edge));
            Edge* edgeTwo = malloc(sizeof(Edge));
            if (edgeOne != NULL && edgeTwo != NULL)
            {
                edgeOne->data = graph->vertex[endIndex].data;
                edgeOne->next = graph->vertex[startIndex].first;
                graph->vertex[startIndex].first = edgeOne;
                edgeTwo->data = graph->vertex[startIndex].data;
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
    }
}

inline void printATGraph(Graph* graph)
{
    printf("ATGraph:\n");
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("%c", graph->vertex[i].data);
        Edge* edge = graph->vertex[i].first;
        while (edge != NULL)
        {
            printf("->%c", edge->data);
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
