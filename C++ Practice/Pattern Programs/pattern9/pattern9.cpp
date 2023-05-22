/*

Pattern 9

1
2 1
3 2 1
4 3 2 1


*/

#include <iostream>
using namespace std;

int main()
{
  int i, j, k = 1;
  for (i = 1; i <= 4; i++)
  {
    k = i;
    for (j = 1; j <= i; j++)
    {

      cout << k << " ";
      k--;
    }
    cout << "\n";
  }
  return 0;
}
