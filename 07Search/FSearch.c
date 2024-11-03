#include <stdio.h>

// 折半查找
int binarySearch(int data[], int key, int length);

int main()
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", binarySearch(data, 5, 10));
    return 0;
}

int binarySearch(int data[], int key, int length)
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
