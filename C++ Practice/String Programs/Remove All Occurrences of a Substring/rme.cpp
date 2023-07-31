#include <iostream>
using namespace std;
int main()
{
  string s("axxxxyyyyb");
  string part("xy"); 

  int l = s.length();   
  cout << s << endl;
  int k = s.find(part);
  while(k > -1)
  {
    s.erase(s.begin()+k, (s.begin()+k+part.length()));
    k = s.find(part);
    cout << s << endl;
  } 
  cout << s;
}