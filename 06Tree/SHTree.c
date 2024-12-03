#include <SHTree.h>

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\06Tree.SHTree.exe
// a1b2c3d4e5f6g7h8
// a: 11110
// b: 11111
// c: 1110
// d: 100
// e: 101
// f: 110
// g: 00
// h: 01
//
// Process finished with exit code 0

int main()
{
    int length = 4;
    SHTree tree = NULL;
    initiateSHTree(&tree, length);
    buildSHTree(&tree, length);
    buildSHTreeCode(&tree, length);
    return 0;
}
