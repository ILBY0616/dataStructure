#include <SString.h>

int main()
{
    char* a = "goodgoogle";
    char* b = "google";
    SString mainString = NULL, patternString = NULL;
    buildSString(a, &mainString);
    buildSString(b, &patternString);
    printSString(mainString);
    printSString(patternString);
    printf("%d", matchSString(mainString, patternString) + 1);
    destroySString(&mainString);
    destroySString(&patternString);
    return 0;
}
