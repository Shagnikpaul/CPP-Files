/*

Pattern 4

1 2 3 4
5 6 7 8
9 10 11 12


*/

#include<iostream>
using namespace std;

int main()
{
    int i,j,k=1;
    for(i=1;i<=4;i++)
    {
      for(j=1;j<=4;j++)
      {
        cout << k << " ";
        k++;
      }
      cout << "\n";
    }
    return 0;
}