#include <iostream>
#include <vector>


using namespace std;

template <typename T, int count>
class Lol
{
public:
    Lol()
    {
        for (int i = 0; i < count; i++)
        {
            cout << "lol" << endl;
        }
    }
};

template <typename X>
class Two
{
private:
    int ax;
    X a, b;

public:
    Two(X a, X b)
    {
        cout << "Oh joy ! " << a << endl;
    }
    X joe(X mama);
};

template <typename X>
X Two<X>::joe(X a)
{
    cout << "You just got joeMamad" << endl;
}

template <class X>
X fun(X a, X b)
{
    return a;
}

int main()
{
    cout << fun(2, 4) << endl;
    cout << fun(2.4, 4.6) << endl;
    cout << fun("qwd", "qwe") << endl;
    Two<string> a("qwd", "qwd");
    a.joe("What");
    Lol<int, 3> l;


    vector<int>::iterator it1;
    
}