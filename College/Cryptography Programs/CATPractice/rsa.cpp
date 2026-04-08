#include <iostream>
using namespace std;
int main()
{
    int p, q;
    cout << "p: ";
    cin >> p;
    cout << "q: ";
    cin >> q;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    cout << "e: ";
    int e;
    cin >> e;
    cout << "pt : ";
    int pt;
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

    cout << "Cipher text : ";
    int ct = 1;
    for (int i = 0; i < e; i++)
    {
        ct = (ct * pt) % n;
    }
    cout << ct;
    cout << "\nPlan text : ";
    int dpt = 1;
    for (int i = 0; i < d; i++)
    {
        dpt = (ct * dpt) % n;
    }
    cout << dpt;
}