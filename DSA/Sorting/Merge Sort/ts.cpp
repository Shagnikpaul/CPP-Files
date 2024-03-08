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



void mergeSort(int arr[], int l, int r) {
    int mid = (r + l) / 2;

    if (l >= r)
    {
        return;
    }
    else
    {
        mergeSort(arr, l,mid);
        mergeSort(arr,  mid + 1,r);
        mergeArray(arr, mid, r, l);
    }
}


int main()
{
     int arr[] = {1, 7, 3, -2, 3, 0};
    mergeSort(arr, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ", ";
    }
}