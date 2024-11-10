
/*

Sample Input

9 (N)
2, 1, 6, 10, 4, 1, 3, 9, 7 (Array Elements)

Sample Output

2, 1, 6, 10, 4, 1, 3, 9, 7
1, 1, 2, 10, 4, 6, 3, 9, 7
1, 1, 2, 3, 4, 6, 7, 9, 10
1, 1, 2, 3, 4, 6, 7, 9, 10
1, 1, 2, 3, 4, 6, 7, 9, 10
1, 1, 2, 3, 4, 6, 7, 9, 10
1, 1, 2, 3, 4, 6, 7, 9, 10
1, 1, 2, 3, 4, 6, 7, 9, 10 (final sorted array)

*/

#include <stdio.h>

void QuickSort(int *arr, int l, int h, int n);
int partition(int *arr, int l, int h, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d, ", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i != (n - 1))
        {
            printf("%d, ", arr[i]);
        }
        else
        {
            printf("%d\n", arr[i]);
        }
    }
    QuickSort(arr, 0, n - 1, n);
    for (int i = 0; i < n; i++)
    {
        if (i != (n - 1))
            printf("%d, ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0;
}

void QuickSort(int *arr, int l, int h, int n)
{

    if (l < h)
    {
        int p = partition(arr, l, h, n);
        QuickSort(arr, l, p - 1, n);
        QuickSort(arr, p + 1, h, n);
        for (int i = 0; i < n; i++)
        {
            if (i != (n - 1))
            {
                printf("%d, ", arr[i]);
            }
            else
            {
                printf("%d\n", arr[i]);
            }
        }
    }
}

int partition(int *arr, int l, int h, int n)
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