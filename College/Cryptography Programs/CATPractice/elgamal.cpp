#include <iostream>
using namespace std;
int main()
{
    int p;
    int e1;
    int d, r;
    cout << "p:";
    cin >> p;
    cout << "e1: ";
    cin >> e1;
    cout << "d: ";
    cin >> d;
    cout << "r: ";
    cin >> r;
    cout << "pt: ";
    int pt;
    cin >> pt;

    int c1, c2;
    int e2 = 1;

    // e2 = (e1 ^ d)%p;

    for (int i = 0; i < d; i++)
        e2 = (e2 * e1) % p;

    c1 = 1;

    for (int i = 0; i < r; i++)
        c1 = (c1 * e1) % p;
    c2 = 1;
    for (int i = 0; i < r; i++)
        c2 = (c2 * e2) % p;
    c2 = (c2 * pt) % p;

    cout << "( " << c1 << ", " << c2 << ")" << endl;

    int s = 1;

    for (int i = 0; i < d; i++)
    {
        s = (s * c1) % p;
    }
    int s2 = 1;
    for (int i = 0; i < (p - 2); i++)
    {
        s2 = (s2 * s) % p;
    }

    int dpt = (s2 * c2) % p;

    cout << "Decrytpted plain text : " << dpt;
}