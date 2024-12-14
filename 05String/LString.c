#include <LString.h>

int main()
{
    char* a = "goodgoogle";
    char* b = "google";
    LString mainString = NULL, patternString = NULL;
    buildLString(a, &mainString);
    buildLString(b, &patternString);
    printLString(mainString);
    printLString(patternString);
    printf("%d", matchLString(mainString, patternString) + 1);
    destroyLString(&mainString);
    destroyLString(&patternString);
    return 0;
}
