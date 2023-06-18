#include <iostream>
#include "algorithm"
#include "vector"


using namespace std;
int main()
{
  vector<int> i;
  

  i.push_back(1);
  
  i.push_back(2);
  
  i.push_back(78);
 
  i.push_back(23);
  
  i.push_back(0);

  sort(i.begin(), i.end());

  cout << "Does 69 exist? " << binary_search(i.begin(), i.end(), 0) << endl;

  // min(a,b) , max(a,b), swap(a,b)
  // reverse a list reverse(a.begin(), a.end()) it can be a string as well
  // rotate(a.begin(), middle element , a.end())
}