#include <iostream>
using namespace std;

int main()
{
  int f = 0, l;
  int mid = 0;
  int peak = 0;
  int arr[] = {7, 9, 10, 1, 2, 3};
  l = ((sizeof(arr) / 4) - 1);
  mid = f + (l - f) / 2;
  while (f < l)
  {
    if (arr[mid] > arr[0])
    {
      f = mid + 1;
    }
    else
    {
      l = mid;
    }
    mid = f + (l - f) / 2;
  }

  cout << "pivot element I got is " << arr[l] << " at index " << l;
}