/*

Pattern 18

****
***
**
*

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;

  for (i = 1; i <= 4; i++)
  {
    for (j = i; j <= 4; j++)
    {
      cout << "*";
    }
    for (j = 1; j <= (i - 1); j++)
    {
      cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
