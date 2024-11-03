#include "ATGraph.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\08Graph.ATGraph.exe
// Input vertexSum edgeSum:
// 2 2
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input startIndex endIndex:
// 0 1
// Input startIndex endIndex:
// 1 0
// ATGraph:
// a->b
// b->a
// Input vertexSum edgeSum:
// 2 1
// Input vertex 0's value:
// a
// Input vertex 1's value:
// b
// Input startIndex endIndex:
// 0 1
// ATGraph:
// a->b
// b->a
//
// Process finished with exit code 0

int main()
{
    ATGraph graph = NULL;
    initiateATGraph(&graph);
    createDATGraph(graph);
    printATGraph(graph);
    destroyATGraph(&graph);
    initiateATGraph(&graph);
    createUATGraph(graph);
    printATGraph(graph);
    destroyATGraph(&graph);
    return 0;
}
