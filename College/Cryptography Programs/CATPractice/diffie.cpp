#include <iostream>
using namespace std;
int main()
{
    int x, y, g;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "g: ";
    cin >> g;
    cout << "P: ";
    int p;
    cin >> p;
    int pX = 1, pY = 1;
    for (int i = 0; i < x; i++)
        pX = (pX * g) % p;
    for (int i = 0; i < y; i++)
        pY = (pY * g) % p;
    int aK = 1;
    for (int i = 0; i < x; i++)
    {
        aK = (aK * pY) % p;
    }

    cout << "Sysm key : " << aK;
}