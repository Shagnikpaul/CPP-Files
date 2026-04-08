#include <iostream>
using namespace std;

int modExp(int base, int exp, int mod)
{
    int result = 1;
    base %= mod;
    for (int i = 0; i < exp; i++)
    {
        result = (result * base) % mod;
    }
    return result;
}

int modInverse(int x, int q)
{
    return modExp(x, q - 2, q);
}

int main()
{
    int hm, p, q, e0, d, r;
    cout << "Enter p: ";
    cin >> p;
    cout << "Enter q: ";
    cin >> q;
    cout << "Enter e0: ";
    cin >> e0;
    cout << "Enter d: ";
    cin >> d;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter h(m): ";
    cin >> hm;
    int e1 = modExp(e0, (p - 1) / q, p);
    int e2 = modExp(e1, d, p);
    int s1 = modExp(e1, r, p) % q;
    int s2 = ((hm + d * s1) * modInverse(r, q)) % q;
    cout << "Public key: (" << e1 << ", " << e2 << ", " << p << ", " << q << ")" << endl;
    cout << "sig1: " << s1 << endl;
    cout << "sig2: " << s2 << endl;
    int w = modInverse(s2, q);
    int a = (hm * w) % q;
    int b = (s1 * w) % q;
    int V = ((modExp(e1, a, p) * modExp(e2, b, p)) % p) % q;
    cout << "V: " << V << endl;
    if (V == s1)
        cout << "Signature Verified" << endl;
    else
        cout << "Signature Invalid" << endl;
    return 0;
}