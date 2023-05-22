/*

Pattern 16

D
C D
B C D
A B C D

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;
  char k = 'D';
  for (i = 1; i <= 4; i++)
  {
    k = 'D' - (i - 1);
    for (j = 1; j <= i; j++)
    {
      cout << char(k) << " ";
      k++;
    }
    cout << "\n";
  }
  return 0;
}
