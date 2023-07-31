#include <iostream>
using namespace std;
int main()
{
  if (3 > 1)
  {
    cout << "Yes 1 is smaller" << endl;
  }
  else
  {
    cout << "No 1 is Larger" << endl;
  }

  // nested ....

  if (3 > 1)
  {
    if (3 > 2)
    {
      cout << "yes 2 and 1 is smaller than 3" << endl;
    }
    else
    {
      cout << "only 1 is smaller than 3" << endl;
    }
  }
  else
  {
    cout << "No 1 is Larger" << endl;
  }
}