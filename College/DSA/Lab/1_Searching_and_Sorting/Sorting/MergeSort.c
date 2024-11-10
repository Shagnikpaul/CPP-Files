#include "stdio.h"

void MergeSort(int *arr, int l, int u);
void Merge(int *arr, int l, int u);

int main()
{
    //// write da code here...
    int arr[] = {4, 1, 3, 9, 7};
    int n = (sizeof(arr) / sizeof(int));
    printf("\nOriginal : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    MergeSort(arr, 0, n - 1);
    printf("\nSorted : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void MergeSort(int *arr, int l, int u)
{
    if (l == u)
    {
        return;
    }
    int mid = (u + l) / 2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, u);
    Merge(arr, l, u);
}

void Merge(int *arr, int l, int u)
{
    // create 2 auxillary arrays
    if (u == l)
    {
        return;
    }
    int mid = (u + l) / 2;
    int n1 = mid - l + 1;
    int n2 = u - mid;
    //printf("Division in n1 = %d n2 = %d\n", n1, n2);
    int one[n1];
    int two[n2];

    for (int i = 0; i < n1; i++)
    {
        one[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        two[i] = arr[i + mid + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while ((i < n1) && (j < n2))
    {
        if (one[i] > two[j])
        {
            arr[k++] = two[j++];
        }
        else
        arr[k++] = one[i++];
    }

    while (i < n1)
    {
        arr[k++] = one[i++];
    }

    while (j < n2)
    {
        arr[k++] = two[j++];
    }
}
