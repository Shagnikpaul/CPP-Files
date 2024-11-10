#include <stdio.h>

void QuickSort(int *arr, int l, int h);
int partition(int *arr, int l, int h);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d, ", &arr[i]);
    }
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i != (n - 1))
            printf("%d, ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0;
}

void QuickSort(int *arr, int l, int h)
{

    if (l < h)
    {
        int p = partition(arr, l, h);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, h);
    }
}

int partition(int *arr, int l, int h)
{
    int p = l;
    int i = p;

    for (int j = p + 1; j <= h; j++)
    {
        if (arr[j] < arr[p])
        {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[p];
    arr[p] = arr[i];
    arr[i] = t;
    return i;
}