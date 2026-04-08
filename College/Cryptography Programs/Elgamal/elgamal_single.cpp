#include <iostream>
using namespace std;

int main()
{
    int p, e1, d, r, pt;

    cout << "Enter prime number (p): ";
    cin >> p;

    cout << "Enter primitive root (e1): ";
    cin >> e1;

    cout << "Enter private key (d): ";
    cin >> d;

    cout << "Enter random secret (r): ";
    cin >> r;

    cout << "Enter plain text (< p): ";
    cin >> pt;

    // e2 = e1^d mod p   (Public key component)
    int e2 = 1;
    for (int i = 0; i < d; i++)
        e2 = (e2 * e1) % p;

    // -------- Encryption --------
    // c1 = e1^r mod pa
    int c1 = 1;
    for (int i = 0; i < r; i++)
        c1 = (c1 * e1) % p;

    // e2^r mod p
    int e2r = 1;
    for (int i = 0; i < r; i++)
        e2r = (e2r * e2) % p;

    // c2 = m * (e2^r) mod p
    int c2 = (pt * e2r) % p;

    cout << "\nCipher Text: (" << c1 << ", " << c2 << ")\n";

    // -------- Decryption --------
    // s = c1^d mod p
    int s = 1;
    for (int i = 0; i < d; i++)
        s = (s * c1) % p;

    // s^{-1} = s^(p-2) mod p   (Fermat's Little Theorem)
    int s_inv = 1;
    for (int i = 0; i < p - 2; i++)
        s_inv = (s_inv * s) % p;

    // m = c2 * s^{-1} mod p
    int decrypted = (c2 * s_inv) % p;
    cout << "Decrypted Plain Text: " << decrypted << endl;
    return 0;
}