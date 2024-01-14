#include <iostream>
using namespace std;

int bs(int u, int l, int key, int arr[])
{
    int mid = u - (u - l) / 2;
    if(u>l)
    return 0;
    if(arr[mid] == key)
    return 1;

    if(arr[mid] > key)
    {
        l = mid - 1;
        return bs(u,l,key,arr);
    }
    else
    {
        u = mid + 1;
        return bs(u,l,key,arr);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    cout << "IsPresent ?  " << bs(0,5,1,arr) << endl;
}