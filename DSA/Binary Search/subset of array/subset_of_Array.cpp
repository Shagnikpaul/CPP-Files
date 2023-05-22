//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends

bool binarySearch(int arr[], int k, int size)
{
  int s = 0;
  int e = size - 1;
  int mid = s + (e - s) / 2;
  while (s <= e)
  {
    mid = s + (e - s) / 2;

    // Check if x is present at mid
    if (arr[mid] == k)
      return true;

    // If x greater, ignore left half
    if (arr[mid] < k)
      s = mid + 1;

    // If x is smaller, ignore right half
    else
      e = mid - 1;
  }

  // if we reach here, then element was
  // not present
  return false;
}

string isSubset(int a1[], int a2[], int n, int m)
{
  int i, c = 0;
  for (i = 0; i < m; i++)
  {
    if (binarySearch(a1, a2[i], n))
    {
      cout << a2[i] << " Present ? yes \n";
      continue;
    }
    else
    {
      cout << a2[i] << " Present ? no \n";
       c = 1;
    }
  }
  if (c == 0)
  {
    return "Yes";
  }
  else
  {
    return "No";
  }
}
int main()
{
  int a1[] = {8,4,5,3,1,7,9};
  int a2[] = {5,1,3,7,9};
  int n = 7;
  int m = 5;
  string k = isSubset(a1,a2,n,m);
  cout << k;
}