#include <iostream>
using namespace std;
int main()
{
  int n = 1;
label:
  cout << n << ", ";
  if (n < 10)
  {
    n++;
    goto label;
  }
  cout << "\a beep!";
  return 0;
}