// C++ Code to explain why
// not clearing the input
// buffer causes undesired
// outputs
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a;
  char ch[80];

  // Enter input from user
  // - 4 for example
  cout << "Enter a number : ";
  cin >> a;

  // Get input from user -
  // "GeeksforGeeks" for example

  cin.getline(ch, 80);

  // Prints 4
  cout << a << endl;
  string name;
  cout << "Enter your full name";
  std::getline(std::cin,name);

      // Printing string : This does
      // not print string
      cout
      << ch << endl;
  cout << "Your name is " << name;
  return 0;
}
