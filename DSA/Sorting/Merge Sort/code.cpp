#include <iostream>
using namespace std;

void mergeArray(int *arr, int mid, int high, int low)
{
    int sorted[high + 1];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] >= arr[j])
            sorted[k++] = arr[j++];
        else
            sorted[k++] = arr[i++];
    }

    while (i <= mid)
    {
        sorted[k++] = arr[i++];
    }

    while (j <= high)
    {
        sorted[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = sorted[i - low];
    }
    return;
}

void mergeSort(int *arr, int h, int l)
{
    int mid = (h + l) / 2;

    if (l >= h)
    {
        return;
    }
    else
    {
        mergeSort(arr, mid, l);
        mergeSort(arr, h, mid + 1);
        mergeArray(arr, mid, h, l);
    }
}

int main()
{
    int arr[] = {1, 7, 3, -2, 3, 0};
    mergeSort(arr, 5, 0);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ", ";
    }
}

/*

Time complexity O( n * log2(n) ) cuz its dividing the array into 2 halves every step....
Worst Case O(n) when every element needs to be compared
Space Complexity O(N) due to the merge function.... 
*/