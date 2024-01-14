#include <iostream>
using namespace std;

bool Lins(int *arr, int s, int key)
{
    if (s == 0)
        return false;
    if (arr[0] == key)
        return true;
    else
    {
        return Lins((arr + 1), (s - 1), key);
    }
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 6};
    int size = 6;

    cout << "Is present " << Lins(arr, size, 6) << endl;
}