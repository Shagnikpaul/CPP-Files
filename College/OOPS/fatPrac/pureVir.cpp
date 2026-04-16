#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func() = 0;
};

class Deri : public Base
{
    void func()
    {
        cout << "LOL";
    }
};

int main()
{
    Base *b;
    Deri d;
    b = &d;
    b->func();
}