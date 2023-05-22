#include <iostream>
using namespace std;

int main()
{
  int f = 0, l;
  int mid = 0;
  int peak = 0;
  int nums[] = {3, 4, 5, 1};
  l = ((sizeof(nums) / 4) - 1);
  mid = f + (l - f) / 2;
  while (f < l)
  {
    if (nums[mid] < nums[mid + 1])
    {
      f = mid + 1;
    }

    else
    {
      l = mid;
    }
    mid = f + (l - f) / 2;
  }

  cout << "peak I got is " << nums[l];
}