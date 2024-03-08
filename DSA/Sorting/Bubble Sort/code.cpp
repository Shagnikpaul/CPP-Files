#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, -6, 4, 3, 66, -33, 4, 333, 22, 0};
    int n = 10, didSwap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        didSwap=0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if(didSwap==0)
        break;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << ", ";
    }
}