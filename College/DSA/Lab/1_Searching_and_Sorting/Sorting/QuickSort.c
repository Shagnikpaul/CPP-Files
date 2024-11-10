#include "stdio.h"

void QS(int *arr, int l, int h);
int partition(int *arr, int p, int h);

int main()
{
    //// write da code here...
    int arr[] = {2, 1, 6, 10, 4, 1, 3, 9, 7 };
    int n = (sizeof(arr) / sizeof(int));
    printf("Original : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    QS(arr, 0, n - 1);
    printf("\nSorted : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void QS(int *arr, int p, int h)
{
    if (p > h)
    {
        return;
    }

    int q = partition(arr, p, h);
    // q is the element we are fixing the position for... so we wont include that in further QuickSort operations....
    QS(arr, p, q - 1);
    QS(arr, q + 1, h);
}

int partition(int *arr, int p, int h)
{
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
    int t = arr[i];
    arr[i] = arr[p];
    arr[p] = t;
    return i;
}
