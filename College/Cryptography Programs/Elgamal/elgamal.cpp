#include <iostream>
using namespace std;

int main() {
    int p, e1, d, r, plainText;

    cout << "Enter prime number (p): ";
    cin >> p;
    cout << "Enter public key (e1): ";
    cin >> e1;
    cout << "Enter private key (d): ";
    cin >> d;
    cout << "Enter random secret (r): ";
    cin >> r;
    cout << "Enter plain text: ";
    cin >> plainText;
    int e2 = 1;
    for(int i = 0; i < d; i++)
        e2 = (e2 * e1) % p;

    int tempPlain = plainText;
    cout << "\nCipher Text:\n";
    int decryptedDigits[20];
    int index = 0;
    while (tempPlain > 0 || (plainText < p && index == 0)) {
        int m;
        if (plainText >= p) {
            m = tempPlain % 10;
            tempPlain /= 10;
        } else {
            m = plainText;
            tempPlain = 0;
        }
        int c1 = 1;
        for(int i = 0; i < r; i++)
            c1 = (c1 * e1) % p;
        int e2r = 1;
        for(int i = 0; i < r; i++)
            e2r = (e2r * e2) % p;
        int c2 = (m * e2r) % p;
        cout << "(" << c1 << ", " << c2 << ") ";
        int s = 1;
        for(int i = 0; i < d; i++)
            s = (s * c1) % p;
        int s_inv = 1;
        for(int i = 0; i < p - 2; i++)
            s_inv = (s_inv * s) % p;
        int pt = (c2 * s_inv) % p;
        decryptedDigits[index++] = pt;
    }
    cout << "\n\nDecrypted Plain Text: ";
    for(int i = index - 1; i >= 0; i--)
        cout << decryptedDigits[i];
    return 0;
}