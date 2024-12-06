#include <stdio.h>

// 折半查找
int foldSearch(int* data, int key, int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\07Search.FoldSearch.exe
// 5
// Process finished with exit code 0

int main()
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", foldSearch(data, 5, 10));
    return 0;
}

int foldSearch(int* data, int key, int length)
{
    int low = 0, high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == key)
        {
            return mid;
        }
        if (data[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
