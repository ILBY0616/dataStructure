#include "AMGraph.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\08Graph.AMGraph.exe
// Input vertexSum edgeSum:
// 2 2
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input startVertex endVertex:
// a b
// Input startVertex endVertex:
// b a
// AMGraph:
// 0 1
// 1 0
// Input vertexSum edgeSum:
// 2 1
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input startVertex endVertex:
// a b
// AMGraph:
// 0 1
// 1 0
//
// Process finished with exit code 0

int main()
{
    AMGraph graph = NULL;
    initiateAMGraph(&graph);
    createDAMGraph(graph);
    printAMGraph(graph);
    destroyAMGraph(&graph);
    initiateAMGraph(&graph);
    createUAMGraph(graph);
    printAMGraph(graph);
    destroyAMGraph(&graph);
    return 0;
}
