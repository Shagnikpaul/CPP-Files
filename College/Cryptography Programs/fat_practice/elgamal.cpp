#include <iostream>
using namespace std;
int main()
{
    int p, e1, e2, c1, c2, d, r;
    cout << "p: ";
    cin >> p;
    cout << "e1: ";
    cin >> e1;
    cout << "d: ";
    cin >> d;
    cout << "r: ";
    cin >> r;
    int pt;
    cout << "pt: ";
    cin >> pt;
    e2 = 1;
    for (int i = 0; i < d; i++)
    {
        e2 = (e2 * e1) % p;
    }

    c1 = 1;
    for (int i = 0; i < r; i++)
    {
        c1 = (c1 * e1) % p;
    }

    c2 = 1;
    for (int i = 0; i < r; i++)
    {
        c2 = (c2 * e2) % p;
    }
    c2 = (c2 * pt) % p;

    cout << "c1 " << c1 << " c22 " << c2 << endl;

    int dpt = 1;

    for (int i = 0; i < (p - d - 1); i++)
    {
        dpt = (dpt * c1) % p;
    }
    dpt = (c2 * dpt) % p;

    cout << "decrptred : " << dpt;
}