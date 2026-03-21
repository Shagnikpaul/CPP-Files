#include <iostream>
using namespace std;

int modInverse(int x, int p)
{
    int result = 1;
    for (int i = 0; i < p - 2; i++)
        result = (result * x) % p;
    return result;
}

void pointAdd(int x1, int y1, int x2, int y2, int a, int p, int &xr, int &yr)
{
    int lambda;
    if (x1 == x2 && y1 == y2)
    {
        int num = (3 * x1 * x1 + a) % p;
        int den = (2 * y1) % p;
        lambda = (num * modInverse(den, p)) % p;
    }
    else
    {
        int num = (y2 - y1 + p) % p;
        int den = (x2 - x1 + p) % p;
        lambda = (num * modInverse(den, p)) % p;
    }
    xr = (lambda * lambda - x1 - x2) % p;
    if (xr < 0)
        xr += p;
    yr = (lambda * (x1 - xr) - y1) % p;
    if (yr < 0)
        yr += p;
}

void scalarMultiply(int x, int y, int k, int a, int p, int &xr, int &yr)
{
    xr = x;
    yr = y;
    for (int i = 1; i < k; i++)
        pointAdd(xr, yr, x, y, a, p, xr, yr);
}

int main()
{
    int a, b, p;
    int gx, gy;
    int d, k;
    int mx, my;
    cout << "Enter curve parameter a: ";
    cin >> a;
    cout << "Enter curve parameter b: ";
    cin >> b;
    cout << "Enter prime number (p): ";
    cin >> p;
    cout << "Enter generator point G (x y): ";
    cin >> gx >> gy;
    cout << "Enter private key (d): ";
    cin >> d;
    cout << "Enter random secret for encryption (k): ";
    cin >> k;
    cout << "Enter plain text point (x y): ";
    cin >> mx >> my;
    int pubx, puby;
    scalarMultiply(gx, gy, d, a, p, pubx, puby);
    cout << "\nPublic Key (e1, e2): (" << pubx << ", " << puby << ")";
    cout << "\nPrime Number: " << p;
    int c1x, c1y;
    scalarMultiply(gx, gy, k, a, p, c1x, c1y);
    int sx, sy;
    scalarMultiply(pubx, puby, k, a, p, sx, sy);
    int c2x, c2y;
    pointAdd(mx, my, sx, sy, a, p, c2x, c2y);
    cout << "\nCipher Text:";
    cout << "\nC1: (" << c1x << ", " << c1y << ")";
    cout << "\nC2: (" << c2x << ", " << c2y << ")";
    int dx1, dy1;
    scalarMultiply(c1x, c1y, d, a, p, dx1, dy1);
    int negy = (p - dy1) % p;
    int dx, dy;
    pointAdd(c2x, c2y, dx1, negy, a, p, dx, dy);
    cout << "\nDecrypted Plain Text: (" << dx << ", " << dy << ")";
    return 0;
}