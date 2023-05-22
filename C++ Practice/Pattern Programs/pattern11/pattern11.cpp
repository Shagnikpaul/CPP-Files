/*

Pattern 11

A B C D
E F G H
I J K L
M N O P

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
      k++;
    }

    cout << "\n";
  }
  return 0;
}
