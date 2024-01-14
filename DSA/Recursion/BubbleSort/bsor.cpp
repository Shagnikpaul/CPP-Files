#include <iostream>
using namespace std;

void bsort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }

    for(int i=0;i<size-1;i++)
    {
        if(arr[i] > arr[i+1])
        swap(arr[i], arr[i+1]);
    }

    bsort(arr, size-1);

}


int main()
{
    int arr[] = {1,21,8,2,3,0,9};
    int size = 7;

    bsort(arr, size);

    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << ", ";
    }
}