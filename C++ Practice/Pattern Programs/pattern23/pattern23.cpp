/*

Pattern 23

   1
   11
  12321
 123321

*/

#include <iostream>
using namespace std;

int main()
{
  int i, j,c=0,k=1;

  for (int i = 1; i <= 7; i++)
  {

    // left triangle
    for (int j = 7; j >= i; j--)
    {
      cout << " ";
    }
    for (int k = 1; k < i; k++)
    {
      cout << k;
    }

    // centre line
    if(c==0){
    cout << k;
    k++;}
    else{
      cout << " ";
    }

    // right triangle
    int f = i - 1;
    for (int k = 1; k < i; k++)
    {
      cout << f;
      f--;
    }
    for (int j = 7; j >= i; j--)
    {
      cout << " ";
    }

    cout << "\n";
    if (c==0){
      c=1;
    }
    else{
      c=0;
    }
  }
  return 0;
}
