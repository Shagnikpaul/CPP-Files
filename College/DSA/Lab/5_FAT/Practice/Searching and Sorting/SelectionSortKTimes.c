#include "stdio.h"

void selectionSort(int *arr, int n, int k);

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d, ", &arr[i]);
    }
    selectionSort(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        if (i != (n - 1))
            printf("%d, ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0;
}

void selectionSort(int *arr, int n, int k)
{

    for (int i = 0; i < k; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }
}