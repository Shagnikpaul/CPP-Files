#include <iostream>
using namespace std;

class A; // forward declaration

class B
{
public:
    void hello(A &obj);
};

class A
{
private:
    int x;

public:
    A() { x = 10; } // initialize for safety
    friend void B::hello(A &obj);
};

void B::hello(A &obj)
{
    cout << obj.x;
}

int main()
{
    B b;
    A a;
    b.hello(a);
}