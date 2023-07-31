/*

Pattern 15

A
B C
C D E
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
    k = 'A' + (i-1);
    for (j = 1; j <= i; j++)
    {
      cout << char(k) << " ";
      k++;
    }
    cout << "\n";
  }
  return 0;
}
