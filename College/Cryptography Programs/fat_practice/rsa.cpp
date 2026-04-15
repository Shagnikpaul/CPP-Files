#include <iostream>
using namespace std;
int main()
{
    int p, q, n, phi, e, d;
    cout << "p: ";
    cin >> p;
    cout << "q: ";
    cin >> q;
    cout << "e: ";
    cin >> e;
    int pt;
    cout << "pt: ";
    cin >> pt;
    n = p * q;
    phi = (p - 1) * (q - 1);
    for (int i = 1; i < phi; i++)
    {
        if ((e * i) % phi == 1)
        {
            d = i;
            break;
        }
    }
    cout << "private key " << d << endl;
    int ct = 1;
    for (int i = 0; i < e; i++)
    {
        ct = (ct * pt) % n;
    }
    cout << "CT : " << ct << endl;
    int dpt = 1;
    for (int i = 0; i < d; i++)
    {
        dpt = (dpt * ct) % n;
    }
    cout << "pt : " << dpt << endl;
}