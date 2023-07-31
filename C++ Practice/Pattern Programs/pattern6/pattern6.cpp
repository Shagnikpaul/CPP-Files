/*

Pattern 6

1 
2 2
3 3 3
4 4 4 4


*/

#include<iostream>
using namespace std;

int main()
{
    int i,j;
    for(i=1;i<=4;i++)
    {
      for(j=1;j<=i;j++){
      
        cout << i << " ";
      }
      cout << "\n";
    }
    return 0;
}
