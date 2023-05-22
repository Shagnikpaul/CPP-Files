/*

Pattern 14

A
B C
D E F
G H I J

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
      k++;
    }

    cout << "\n";
  }
  return 0;
}
