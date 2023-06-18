#include <iostream>
using namespace std;
int main()
{
  int a = 21;
  
  int *p = &a;

  
  int *z = 0;
  z = p;
  
  cout << "Address of a is using only & operator " << &a << endl;
  cout << "The value which the pointer *p is referencing to is " << *p << endl;
  cout << "Z " << z << endl;



  int num = 9;

  int *g = &num;

  int k = *g;

  (*g)++;

  cout << "Now num is " << num << endl;

  (k)--;
  cout << "Now k is " << k << endl;

  int t = 9;
  int *u = &t;

  (*u)++;

  cout<< "u is " << *u << endl;


  *u = *u + 1;
  cout << "u is " << *u << endl;

  int j = 0;

  int *o = &j;

 

  cout << "Before Direct addition to the value of a pointer gives " << o << endl;
  o = o + 1; // adds 4 to the hexadecimal number
  cout << "After Direct addition to the value of a pointer gives " << o << endl;
}