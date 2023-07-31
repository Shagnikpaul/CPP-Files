#include <iostream>
#include "deque"
using namespace std;
int main()
{
  deque<int> d;
  /*
    in deq elements can be added from front as well as back
    from front = d.push_front();
    from back = d.push_back();

  */

  d.push_front(1);
  d.push_front(2);
  d.push_front(3);
  d.push_back(4);
  d.push_back(5);
  d.push_back(6);
  for(int i: d){
    if (i == d.back())
    {
      cout << i;
      break;
    }
    cout << i << ", ";
  }
  cout << endl;
  cout << "Notice the order" << endl;


/*
  remove element from beginning  = d.pop_front();
  for back = d.pop_back();
  
*/

/*
  front ele = d.front()
  last ele = d.back()
  is empty = d.empty() 0 for false

  d.erase(from, to) -> it requires a range and the last element is excluded that is not deleted...

  example - > 

  d.erase(d.begin(), d.begin()+1) -> this only deletes the first element of the deq.... since the ending of range is excluded...



*/

cout << "Size before d.erase() = " << d.size()  << endl;
d.erase(d.begin(), d.begin()+1);
cout << "Size after d.erase() = " << d.size() << endl;

// write some code...
}