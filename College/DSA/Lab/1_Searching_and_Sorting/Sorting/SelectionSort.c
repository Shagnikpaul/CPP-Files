#include "stdio.h"
int main()
{
    //// write da code here...
    int arr[] = {-1, 9, 2, 33, -12, 0, 43};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n - 1; i++)
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

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}