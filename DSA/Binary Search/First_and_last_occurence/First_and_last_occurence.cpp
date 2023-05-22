#include <iostream>
using namespace std;

int main()
{
  int f = 0, l;
  int mid = 0;
  int min = 0;
  int key = 6;
  int ans = 0;
  int arr[] = {1,
               2,
               2,
               3,
               3,
               3,
               6,
               6,
               6,
               6,
               7,
               8,
               9};
  l = ((sizeof(arr) / 4) - 1);
  mid = f + (l - f) / 2;
  cout << "[INFO] first index = " << f << "\n";
  cout << "[INFO] last index = " << l << "\n";
  cout << "[INFO] starting mid index = " << mid << "\n";
  while (f <= l)
  {
    if (arr[mid] == key)
    {
      ans = mid;
      l = mid - 1;
    }
    else if (key > arr[mid])
    {
      f = mid + 1;
    }
    else
    {
      l = mid - 1;
    }
    mid = f + (l - f) / 2;
  }

  cout << "[SOLUTION] FIRST OCCURENCE of "<< key << " I GOT IS AT INDEX = " << ans;
}