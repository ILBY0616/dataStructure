#include "AMGraph.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\08Graph.AMGraph.exe
//// Input vertexSum edgeSum:
//// 4 3
//// Input vertex 0's value:
//// a
//// Input vertex 1's value:
//// b
//// Input vertex 2's value:
//// c
//// Input vertex 3's value:
//// d
//// Input weight startIndex endIndex:
//// 1 0 1
//// Input weight startIndex endIndex:
//// 1 1 2
//// Input weight startIndex endIndex:
//// 1 2 0
//// DFS:
//// abc
//// BFS:
//// abc
//// AMGraph:
//// 0 1 2147483647 2147483647
//// 2147483647 0 1 2147483647
//// 1 2147483647 0 2147483647
//// 2147483647 2147483647 2147483647 0
//// Input vertexSum edgeSum:
//// 4 3
//// Input vertex 0's value:
//// a
//// Input vertex 1's value:
//// b
//// Input vertex 2's value:
//// c
//// Input vertex 3's value:
//// d
//// Input weight startIndex endIndex:
//// 1 0 1
//// Input weight startIndex endIndex:
//// 1 1 2
//// Input weight startIndex endIndex:
//// 1 2 0
//// DFS:
//// abc
//// BFS:
//// abc
//// AMGraph:
//// 0 1 1 2147483647
//// 1 0 1 2147483647
//// 1 1 0 2147483647
//// 2147483647 2147483647 2147483647 0
////
//// Process finished with exit code 0

int main()
{
    bool visited[100];
    AMGraph graph = NULL;
    initiateAMGraph(&graph);
    createDAMGraph(graph);
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFSAMGraph(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("BFS:\n");
    BFSAMGraph(graph, 0, visited);
    printf("\n");
    printAMGraph(graph);
    destroyAMGraph(&graph);
    initiateAMGraph(&graph);
    createUAMGraph(graph);
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("DFS:\n");
    DFSAMGraph(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printf("BFS:\n");
    BFSAMGraph(graph, 0, visited);
    printf("\n");
    printAMGraph(graph);
    destroyAMGraph(&graph);
    return 0;
}
