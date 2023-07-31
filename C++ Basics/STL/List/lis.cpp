#include <iostream>

#include "list"
using namespace std;
int main()
{
  list<int> l;
  l.push_back(1);
  l.push_front(2);

  // copying to a new list
  list<int> n(l);

  // initialize by default
  list<int> z(5, 100);
  for (int i : z)
  {
    cout << i << " ";
  }
  cout << endl;

  for (int i : l)
  {
    cout << i << " ";
  }

  // removing elements -> push_back push_front
  // size l.size()
}