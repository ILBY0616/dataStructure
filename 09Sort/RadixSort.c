#include <stdio.h>

// 基数排序
void radixSort(int data[], int length);
// 打印序列
void printData(int data[], int length);

// D:\CLion\WorkPlace\dataStructure\cmake-build-debug\09Sort.RadixSort.exe
// 190 180 170 160 150 140 130 120 110 100
// 100 110 120 130 140 150 160 170 180 190
//
// Process finished with exit code 0

int main()
{
    int data[10] = {190, 180, 170, 160, 150, 140, 130, 120, 110, 100};
    printData(data, 10);
    radixSort(data, 10);
    printData(data, 10);
    return 0;
}

// 基数排序
void radixSort(int data[], int length)
{
    // 循环找到最大数
    int max = data[0];
    for (int i = 1; i < length; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    // 计算最大数位数
    int maxDigit = 0;
    while (max != 0)
    {
        max /= 10;
        maxDigit++;
    }
    // 定义计数器数组和临时存储数组
    int count[10];
    int temp[length];
    // 按位进行排序，从最低位开始
    int divisor = 1;
    for (int digit = 0; digit < maxDigit; digit++)
    {
        // 初始化计数器
        for (int i = 0; i < 10; i++)
        {
            count[i] = 0;
        }
        // 统计当前位数字出现的次数
        for (int i = 0; i < length; i++)
        {
            int bucket = (data[i] / divisor) % 10;
            count[bucket]++;
        }
        // 累计计数器，将其转化为位置索引
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        // 按当前位数字排序，存入临时数组
        for (int i = length - 1; i >= 0; i--)
        {
            int bucket = (data[i] / divisor) % 10; // 提取当前位
            temp[--count[bucket]] = data[i];
        }
        // 将临时数组内容复制回原数组
        for (int i = 0; i < length; i++)
        {
            data[i] = temp[i];
        }
        // 进入下一位
        divisor *= 10;
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
