#include <iostream>
using namespace std;

int somefun(int *p)
{
  cout << "Value I got " << *p << endl;
}

int somef2(int *p)
{
  *p = *p + 1;
}


int main()
{
  int a[] = {1, 2, 3, 4, 5, 6};

  // int *p1 = &a;  this gives error since 'a' is actually a pointer not any standard variable.
  int *p1 = a;
  int *p2 = &a[0];

  // both will give same address...

  cout << "Value of p1 and p2 " << p1 << " " << p2 << endl;

  int p = *(a + 1); // gives 2
  int q = *(a + 3); // gives 4;

  cout << "p and q = " << p << ", " << q << endl;

  int index = 2;

  cout << "Value of index[a] = " << index[a] << endl;

  //       int *l = a++;    gives error

  char c = 'a';
  char *o = &c;
  cout << "o = " << o << endl; // will print a with some garbage values afterwards...


  int k = 90;

  somefun(&k);
  int *t = &k;
  somef2(t);

  cout << "After update is " << k;
}


