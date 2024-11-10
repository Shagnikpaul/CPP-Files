#include "stdio.h"

void countingSort(int *arr, int n, int k);

int main()
{
    //// write da code here...
    int arr[] = {2, 1, 6, 10, 4, 1, 3, 9, 7};
    int n = (sizeof(arr) / sizeof(int));
    printf("Original : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    countingSort(arr, n, 10);
    printf("\n");
    printf("Sorted : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void countingSort(int *arr, int n, int k)
{
    int aux[k + 1];
    int ans[n];
    for (int i = 0; i < k + 1; i++)
    {
        aux[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        aux[arr[i]]++;
    }
    for (int i = 1; i < k + 1; i++)
    {
        aux[i] = aux[i - 1] + aux[i];
    }

    for (int i = n-1; i >= 0; i--)
    {

        //printf("%d, ", aux[arr[i]]);
        ans[aux[arr[i]]-1] = arr[i];
        aux[arr[i]]--;
    }
    // printf("\nNEW SORTED: ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d, ",ans[i]);
    // }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}
