/*
Pattern:
For n = 7

      1
     1 1
    1 2 1
   1 2 2 1
  1 2 3 2 1
 1 2 3 3 2 1
1 2 3 4 3 2 1

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j, c = 0, k = 1;
  int n;
  cout << "Enter a range. ";
  cin >> n;
  n = n*2;
  for (i = 1; i <= n; i++)
  {
    
    // space
    for(j=(n-i);j>=1;j--)
    {
      cout << " ";
    }
    
    
    if (c == 0)
    {
      for (j = 1; j < k; j++)
      {
        cout << j << " ";
      }
      cout << k << " ";
      for (j = (k - 1); j >= 1; j--)
      {
        cout << j << " ";
      }
      k++;
      c = 1;
    }
    else
    {
      for (j = 1; j < k; j++)
      {
        cout << j << " ";
      }
      for (j = (k - 1); j >= 1; j--)
      {
        cout << j << " ";
      }
      c = 0;
    }
    cout << "\n";
  }
  return 0;
}
