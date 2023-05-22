/*
Pattern 2

  1 1 1
  2 2 2
  3 3 3


*/

#include <iostream>
using namespace std;

int main()
{
  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= 3; j++)
    {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}