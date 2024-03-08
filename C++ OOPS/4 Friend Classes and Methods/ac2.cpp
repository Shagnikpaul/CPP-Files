#include <iostream>
using namespace std;
class joe;
class mama;

class base // random class
{
public:
    void addAges(joe &j, mama &m);
};

class joe // parent 1
{

private:
    int age;

public:
    joe()
    {
        age = 22;
    }

    friend void base::addAges(joe &, mama &);
};

class mama // parent 2
{

private:
    int age;

public:
    mama()
    {
        age = 42;
    }
    friend void base::addAges(joe &, mama &);
};

void base::addAges(joe &j, mama &m)
{
    cout << "the sum of the ages of joe and mama = " << (j.age + m.age) << endl;
}

int main()
{
    base b;
    joe j;
    mama m; 
    b.addAges(j,m);
}