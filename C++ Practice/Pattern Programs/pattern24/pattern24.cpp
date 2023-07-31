/*

Pattern 24

1234554321
1234**4321
123****321
12******21
1********1

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j;

  for (int i = 1; i <= 5; i++)
  {
    // part 1 left
    for (j = 1; j <= (5 - (i - 1)); j++)
    {
      cout << j;
    }
    for (j = 1; j <= (i - 1); j++)
    {
      cout << "*";
    }

    // part 2 right...
    for (j = 1; j <= (i - 1); j++)
    {
      cout << "*";
    }
    for (j = (5 - (i - 1)); j >= 1; j--)
    {
      cout << j;
    }

    cout << "\n";
  }
  return 0;
}
