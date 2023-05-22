/*

Pattern 22

1234
 234
  34
   4

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;

  for (i = 1; i <= 4; i++)
  {
    for (j = 1; j <= (i - 1); j++)
    {
      cout << " ";
    }

    for (j = i; j <= 4; j++)
    {
      cout << j;
    }
    cout << "\n";
  }
  return 0;
}
