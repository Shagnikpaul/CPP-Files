#include <iostream>
using namespace std;

int main()
{
    int p, q, n, phi, e, pt;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    cout << "Enter public key (e): ";
    cin >> e;
    cout << "Enter plain text: ";
    cin >> pt;
    int d = 1;
    for (int i = 1; i < phi; i++)
    {
        if ((e * i) % phi == 1)
        {
            d = i;
            break;
        }
    }
    cout << "\nn value: " << n;
    cout << "\nPublic Key (e,n): (" << e << "," << n << ")";
    cout << "\nPrivate Key (d,n): (" << d << "," << n << ")";
    int ct = 1;
    for (int i = 0; i < e; i++)
        ct = (ct * pt) % n;
    cout << "\nCipher Text: " << ct;
    int decrypted = 1;
    for (int i = 0; i < d; i++)
        decrypted = (decrypted * ct) % n;
    cout << "\nDecrypted Plain Text: " << decrypted;
    return 0;
}