#include "stdio.h"

int linearSearch(int *arr, int n, int target);

int main()
{
    //// write da code here...
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n = sizeof(arr) / sizeof(int);

    int target = 6;
    int result = linearSearch(arr, n, target);
    if (result != -1)
    {
        printf("Target %d was found at index %d.\n", target, result);
    }
    else
    {
        printf("Target %d was not found. \n", target);
    }
    return 0;
}

int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}