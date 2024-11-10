#include "stdio.h"

void bubbleSort(int *arr, int n);

int main()
{
    //// write da code here...

    int arr[] = {2, -4, 3, 55, 10, 0, -22, 342, 99};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}