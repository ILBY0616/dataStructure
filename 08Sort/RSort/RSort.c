#include <stdio.h>

// 统一重点：ToDo
// 统一提示：中文
// 统一注释：代码上方
// 统一状态：-1失败，0成功，1其他

// ToDo
// RadixSort

int getMax(int data[], int length) {
    int max = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

void countSort(int data[], int length, int exp) {
    int output[length];
    int count[10] = {0};

    for (int i = 0; i < length; i++) {
        count[(data[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        count[(data[i] / exp) % 10]--;
    }

    for (int i = 0; i < length; i++) {
        data[i] = output[i];
    }
}

void sortData(int data[], int length) {
    int max = getMax(data, length);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(data, length, exp);
    }
}

void printData(int data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    int data[8] = {1990, 1881, 992, 883, 94, 85, 6, 7};
    printData(data, 8);
    sortData(data, 8);
    printData(data, 8);
    return 0;
}
