#include <iostream>
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Constructor ran !!!\n";
    }

    // when a class has a private destructor, only dynamic objects of that class can be created.

private:
    ~Test()
    {
        cout << "destructor ran !!!\n";
    }

    // a way to run a private constructor...
public:
    friend void destroyObject(Test *ptr);
};

void destroyObject(Test *ptr)
{
    delete ptr;
}

int main()
{
    Test *t = new Test();
    destroyObject(t);
}