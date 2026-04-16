#include <iostream>
using namespace std;
class A
{

public:
    int a;
    A(int x)
    {
        this->a = x;
    }

    A operator+(A a1)
    {
        return this->a + a1.a;
    }
};

class space
{

public:
    int x, y, z;
    space(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    space operator-()
    {
        space s(0, 0, 0);
        s.x = -this->x;
        s.y = -this->y;
        s.z = -this->z;
        return s;
    }

    space operator+(space y)
    {
        space g(this->x + y.x, this->y + y.y, this->z + y.z);
        return g;
    }

    friend ostream &operator<<(ostream &i, space &s);
};

ostream &operator<<(ostream &i, space &s)
{
    i << s.x << ", " << s.y << ", " << s.z << endl;
    return i;
}

int main()
{
    A a1(3);
    A aw(5);
    A r = a1 + aw;
    // cout << r.a;
    space d(1, 2, 3);
    space x = -d;
    space l = d + x;
    cout << d;
}