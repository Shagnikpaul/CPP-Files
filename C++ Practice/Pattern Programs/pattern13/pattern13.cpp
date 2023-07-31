/*

Pattern 13

A
B B
C C C
D D D D

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;
  char k = 'A';
  for (i = 1; i <= 4; i++)
  {
    for (j = 1; j <= i; j++)
    {
      cout << char(k) << " ";
     }
    k++;
    cout << "\n";
  }
  return 0;
}
