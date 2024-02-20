#include <iostream>
using namespace std;
bool isSort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] < arr[1])
    {
        bool s = isSort((arr + 1), (size - 1));
        return s;
    }
    else
    {
        return false;
    }
}

int main()
{
    int arr[] = {2, 3, 41, 4, 1};
    int arr2[] = {1, 2, 3, 4, 5};

    int size = 5;
    cout << "is Sorted ? " << isSort(arr2, size) << endl;
}