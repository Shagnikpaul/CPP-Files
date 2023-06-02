#include <iostream>
#include "set"
using namespace std;
int main()
{
    /*
    
    SET - only unique elements will be present in it.
    
    */ 

   set<int> s;

   s.insert(1);
   s.insert(1);
   s.insert(1);
   s.insert(12);
   s.insert(11);
   s.insert(14);

   for(auto i : s) {
    cout << i << " ";
   }
   cout << endl;

   cout << s.count(13) << endl; // returns 0 or 1
}