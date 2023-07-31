#include <iostream>
using namespace std;
int main()
{
  char ch[40];
  cout << "Enter your name : ";
  cin >> ch;
  int l = 0;
  for(int i = 0 ; ch[i] != '\0'; i++)
  l++;
  cout << "Length of the given string is " << l << endl;

  cout << "reversed string " << endl;
  for(int i = l-1; i >=0; i--)
  cout << ch[i];
  cout<< endl;

  
  // ch[2] = '\0';
  // cout << endl << "Hello, " << ch; 

}