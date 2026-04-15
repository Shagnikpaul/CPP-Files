#include <iostream>
using namespace std;

int bMod(int base, int pow, int mod)
{
    base %= mod;
    int x = 1;
    for (int i = 0; i < pow; i++)
    {
        x = (x * base) % mod;
    }
    return x;
}

int main()
{
    int p, q, r, d, e0, hm;
    int e1, e2, s1, s2, v;
    cout << "p: ";
    cin >> p;
    cout << "q: ";
    cin >> q;
    cout << "r: ";
    cin >> r;
    cout << "d: ";
    cin >> d;
    cout << "e0: ";
    cin >> e0;
    cout << "hm: ";
    cin >> hm;

    e1 = 1;
    for (int i = 0; i < ((p - 1) / q); i++)
    {
        e1 = (e1 * e0) % p;
    }

    e2 = 1;
    for (int i = 0; i < d; i++)
    {
        e2 = (e2 * e1) % p;
    }

    s1 = 1;
    for (int i = 0; i < r; i++)
    {
        s1 = (s1 * e1) % p;
    }
    s1 %= q;

    s2 = 1;
    for (int i = 0; i < (q - 2); i++)
    {
        s2 = (s2 * r) % q;
    }
    s2 = (s2 * (hm + s1 * d)) % q;

    cout << "S1 = " << s1 << " S2 = " << s2 << endl;
    int s_inv = 1;
    s_inv = bMod(s2, (q - 2), q);
    v = 1;
    v = (bMod(e1, (hm * s_inv), p) * bMod(e2, (s1 * s_inv), p)) % p;
    v %= q;

    if (s1 == v)
        cout << "Message verified";
    else
        cout << "Message  not verified";
}