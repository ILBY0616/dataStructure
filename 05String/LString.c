#include "LString.h"

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\05String.LString.exe
// goodgoogle
// google
// 4
// Process finished with exit code 0

int main()
{
    char* a = "goodgoogle";
    char* b = "google";
    LString mainString = NULL, patternString = NULL;
    createLString(a, &mainString);
    createLString(b, &patternString);
    printLString(mainString);
    printLString(patternString);
    printf("%d", matchLString(mainString, patternString));
    destroyLString(&mainString);
    destroyLString(&patternString);
    return 0;
}
