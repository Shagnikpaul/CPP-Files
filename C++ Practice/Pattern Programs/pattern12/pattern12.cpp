/*

Pattern 12

A B C D
B C D E
C D E F
D E F G

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;
  char k = 'A';
  for (i = 1; i <= 4; i++)
  {
    k = 'A' + (i - 1);
    for (j = 1; j <= 4; j++)
    {
      cout << char(k) << " ";
      k++;
    }
    cout << "\n";
  }
  return 0;
}
