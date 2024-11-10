#include <stdio.h>

void mergeSort(int *arr, int low, int high);
void merge(int *arr, int l, int h);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d, ", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i != (n - 1))
            printf("%d, ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0;
}

void mergeSort(int *arr, int low, int high)
{
    if (low != high)
    {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high);
    }
    else
    {
        return;
    }
}

// void merge(int *arr, int l, int u)
// {
//     // // create 2 auxillary arrays
//     // if (u == l)
//     // {
//     //     return;
//     // }
//     int mid = (u + l) / 2;
//     int n1 = mid - l + 1;
//     int n2 = u - mid;
//     //printf("Division in n1 = %d n2 = %d\n", n1, n2);
//     int one[n1];
//     int two[n2];

//     for (int i = 0; i < n1; i++)
//     {
//         one[i] = arr[l + i];
//     }

//     for (int i = 0; i < n2; i++)
//     {
//         two[i] = arr[i + mid + 1];
//     }

//     int i = 0;
//     int j = 0;
//     int k = l;
//     while ((i < n1) && (j < n2))
//     {
//         if (one[i] > two[j])
//         {
//             arr[k++] = two[j++];
//         }
//         else
//         arr[k++] = one[i++];
//     }

//     while (i < n1)
//     {
//         arr[k++] = one[i++];
//     }

//     while (j < n2)
//     {
//         arr[k++] = two[j++];
//     }
// }

void merge(int *arr, int l, int h)
{

    if (l == h)
    {
        return;
    }
    int mid = (l + h) / 2;
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int one[n1];
    int two[n2];

    for (int i = 0; i < n1; i++)
    {
        one[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        two[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while ((i < n1) && (j < n2))
    {
        if (one[i] > two[j])
        {
            arr[k++] = two[j];
            j++;
        }
        else
        {
            arr[k++] = one[i];
            i++;
        }
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