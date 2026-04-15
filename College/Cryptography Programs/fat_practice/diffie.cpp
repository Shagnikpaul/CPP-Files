#include <iostream>
using namespace std;
int main()
{
    int p, g, x, y, a, b, sym;
    cout << "p: ";
    cin >> p;
    cout << "g: ";
    cin >> g;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    a = 1;
    for (int i = 0; i < x; i++)
    {
        a = (a * g) % p;
    }

    b = 1;
    for (int i = 0; i < y; i++)
    {
        b = (b * g) % p;
    }

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    sym = 1;
    for (int i = 0; i < y; i++)
    {
        sym = (sym * a) % p;
    }

    cout << "symmetrix key  " << sym;
}