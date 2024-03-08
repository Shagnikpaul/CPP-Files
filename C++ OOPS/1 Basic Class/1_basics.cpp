#include <iostream>
using namespace std;

class person
{
    int age;
    char name[20];

public:
    void sayHello()
    {
        cout << "Hello !" << endl;
    }
};

int main()
{
    person you;
    you.sayHello();
    return 0;
}