#include <stdlib.h>
#include <stdio.h>

#define type int
#define size 100

typedef struct Edge
{
    type endVertex;
    struct Edge* next;
} Edge;

typedef struct Vertex
{
    type startVertex;
    Edge* first;
} Vertex;

typedef struct Graph
{
    Vertex vertexList[size];
    int vertexSum, edgeSum;
} Graph;

// 创建有向图
void createGraph(Graph* graph) // 传指针
{
    printf("请输入顶点的数量和边的数量:\n");
    scanf("%d %d", &graph->vertexSum, &graph->edgeSum);

    // 输入顶点
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("请输入顶点 %d 的值: ", i);
        scanf("%d", &graph->vertexList[i].startVertex);
        graph->vertexList[i].first = NULL;
    }

    // 输入边
    for (int i = 0; i < graph->edgeSum; i++)
    {
        type startVertex, endVertex;
        printf("请输入边的起点和终点: ");
        scanf("%d %d", &startVertex, &endVertex);
        Edge* edge = malloc(sizeof(Edge));
        if (edge != NULL)
        {
            edge->endVertex = endVertex;
            edge->next = graph->vertexList[startVertex].first;
            graph->vertexList[startVertex].first = edge;
        }
    }
}

// 打印邻接表
void printGraph(Graph* graph) // 传指针
{
    for (int i = 0; i < graph->vertexSum; i++)
    {
        printf("顶点 %d: ", graph->vertexList[i].startVertex);
        Edge* edge = graph->vertexList[i].first;
        while (edge != NULL)
        {
            printf("-> %d ", edge->endVertex);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph graph;
    createGraph(&graph); // 传递指针
    printGraph(&graph); // 传递指针
    return 0;
}