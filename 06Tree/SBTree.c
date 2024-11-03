#include "SBTree.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\06Tree.SBTree.exe
//
// Process finished with exit code 0

int main()
{
    SBTree tree = NULL;
    char data[10] = "abcdefghij";
    createSBTree(data, &tree);
    destroySBTree(&tree);
    return 0;
}
