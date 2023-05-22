/*

Pattern 10

A A A A
B B B B
C C C C
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
    for (j = 1; j <= 4; j++)
    {

      cout << char(k) << " ";
    }
    k++;
    cout << "\n";
  }
  return 0;
}
