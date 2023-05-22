#include "iostream"

#include <array>

using namespace std;
int main() {
    
    array<int, 4> a = {1,2,3,4};

    for(int i=0;i<a.size();i++)
    {
      cout << a[i] << ", ";
      
    }
    cout << endl;


    // alternatively we can use a.at(i) to get a particular element....
    cout << "element at 2nd pos " << a.at(1);
    cout << endl;

    // check if array empty or not returns 0 for false...

    cout << "is empty ? " << a.empty() << endl;


    cout << "front and last element of the array " << a.front() << ", " << a.back() << endl;

}
