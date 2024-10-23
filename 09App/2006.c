// 找到递增序列中T[i]=i的下标
int findData(int data[], int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == mid)
        {
            return mid;
        }
        if (data[mid] > mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}


