#include "stdio.h"

void insertionSort(int *arr, int n);

int main()
{
    //// write da code here...
    int arr[] = {2, -4, 3, 55, 10, 0, -22, 342, 99};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}

void insertionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j + 1] < arr[j])
            {
                int t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
            else
            {
                break;
            }
        }
    }
}