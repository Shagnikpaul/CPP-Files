#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double num4 = 3.0;
  double num5 = 3.5;
  cout << "Enter length of side A";
  cin >> num4;
  cout << "Enter length of side B";
  cin >> num5;

  cout << "Length of the hypotenuse is " << sqrt(pow(num4, 2.0) + pow(num5, 2.0));

  return 0;
}