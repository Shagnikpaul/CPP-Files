#include <iostream>
using namespace std;

int modExp(int x, int p, int m)
{
    int a = 1;
    for (int i = 0; i < p; i++)
        a = (a * x) % m;
    return a;
}

int modInv(int x, int q)
{
    return modExp(x, q - 2, q);
}

int main()
{
    int p, q, e0, d, r;
    cout << "p: ";
    cin >> p;
    cout << "q: ";
    cin >> q;
    cout << "e0: ";
    cin >> e0;
    cout << "d: ";
    cin >> d;
    int hm;
    cout << "hm: ";
    cin >> hm;

    cout << "r: ";
    cin >> r;

    // generator g
    int e1 = modExp(e0, ((p - 1) / q), p);
    cout << "e1 : " << e1 << " ((p - 1) / q) " << ((p - 1) / q) << endl;
    // e2
    int e2 = modExp(e1, d, p);

    // s1
    int s1 = modExp(e1, r, p) % q;

    // s2
    int s2 = ((hm + d * s1) % q * modInv(r, q)) % q;

    int invs1 = modInv(s2, q);
    int v = modExp(e1, (hm * invs1), p) * modExp(e2, (s1 * invs1), p);
    v %= p;
    v %= q;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "v=  " << v << endl;
}