/*

INPUT : 1,2,3,4,5,6
OUTPUT : 2 1 4 3 6 5

*/

#include <iostream>
using namespace std;

int main()
{
  int list[] = {1, 2, 3, 4, 5, 6};
  int i, k;
  for (i = 0; i <= 4;)
  {
    k = list[i];
    list[i] = list[i + 1];
    list[i + 1] = k;
    i = i + 2;
  }

  for (i = 0; i < 6; i++)
  {
    cout << list[i] << " ";
  }
  return 0;
}