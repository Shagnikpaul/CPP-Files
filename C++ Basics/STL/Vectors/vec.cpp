#include <iostream>
#include <vector>
using namespace std;
int main()
{
  //write some code...

  // dynamic arrays
  vector<int> i;
  cout << "1st Size of the vector (no insertion yet) = " << i.capacity() << endl;

  i.push_back(1);
  cout << "2nd Size of the vector (1st insertion) = " << i.capacity() << endl;
  i.push_back(1);
  cout << "3rd Size of the vector (2nd insertion) = " << i.capacity() << endl;
  i.push_back(1);
  cout << "4th Size of the vector (3rd insertion) = " << i.capacity() << endl;
  i.push_back(1);
  cout << "5th Size of the vector (4th insertion) = " << i.capacity() << endl;
  i.push_back(1);
  cout << "5th Size of the vector (5th insertion) = " << i.capacity() << endl;

  cout << "Notice how the size of the vector doubles its last size whenever it runs out of space..." << endl;

  cout << "Size of vector and capacity before i.clear() = " << i.size() << ", "<< i.capacity() << endl;
  i.clear();
  cout << "Size of vector and capacity after i.clear() = " << i.size() << ", " << i.capacity() << endl;
  cout << "Notice how the capacity remains same even after removing all the elements..." << endl;



  /*
    initialize elements of a vector by some int

    vector<int> a(5,1); -> means create a initial vector of capacity 5 with all elements init as 1;

    copy one vector to another... 
    vector<int> newone(a); 
  
  */
  /*
    v.size() tells us about current number of elements and 
    v.capacity() tells us the total size of the vector array...
    v.at(2) get element at 2nd positon this is not the index...
    v.front() for 1st ele
    v.back for last ele
    v.pop_back() remove the last inserted element...
  */
}