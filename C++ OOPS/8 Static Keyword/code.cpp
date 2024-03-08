// C++ Program to demonstrate
// the working of static data member
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A's Constructor Called " << endl;
    }
};

class B
{
public:
    static A a;

public:
    B()
    {
        cout << "B's Constructor Called " << endl;
        a = A();
    }
};

// Driver code
int main()
{
    B b;
    A a = B::a;
    return 0;
}
