#include <iostream>
using namespace std;



int update(int **p)
{
  // p = p + 1; // no change

  *p = *p + 1; // yes the p changes

  // **p = **p + 1;
}


int main()
{
  int k = 9;
  int* p = &k;
  int** pp = &p;
  cout << "[BEFORE] " << endl;
  cout << "Content of k " << k << endl;
  cout << "p = " << p << endl;
  cout << "pp = " << pp << endl;
  cout << "Add of it " << &pp << endl;

//   **pp = 21;
  update(pp);

  cout << "\n[AFTER]" << endl;
  cout << "Content of k " << k <<  endl;
  cout << "p = " << p << endl;
  cout << "pp = " << pp << endl;
  cout << "Add of it " << &pp << endl;
}





