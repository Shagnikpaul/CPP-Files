#include <iostream>
using namespace std;
int main()
{
    int p, q, n, phi, e, hm;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    cout << "Enter public key (e): ";
    cin >> e;
    cout << "Enter the hash message h(m) : ";
    cin >> hm;

    int d = 1;
    for (int i = 1; i < phi; i++)
    {
        if ((e * i) % phi == 1)
        {
            d = i;
            break;
        }
    }
    int sig = 1;
    for (int i = 1; i <= d; i++)
    {
        sig = (hm * sig) % n;
    }
    cout << "Signature : " << sig << endl;
    int m_d = 1;
    for (int i = 1; i <= e; i++)
    {
        m_d = (sig * m_d) % n;
    }
    if (hm == m_d)
    {
        cout << "Message accepted";
    }
    else
    {
        cout << "Message not verified";
    }
}