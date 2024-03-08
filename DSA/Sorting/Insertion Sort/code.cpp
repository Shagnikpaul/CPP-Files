#include <iostream>
using namespace std;
int main()
{
    //int arr[] = {1, -6, 4, 3, 66, -33, 4, 333, 22, 0};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10, didSwap = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << ", ";
    }
}