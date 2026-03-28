#include <iostream>

using namespace std;

int hexCharToInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

int conditionalF(int e, int f, int g)
{
    e &= 0xF;
    f &= 0xF;
    g &= 0xF;
    return ((e & f) ^ ((~e & 0xF) & g)) & 0xF;
}

int main()
{
    string e, f, g;
    cout << "Enter the value of E : ";
    getline(cin, e);
    cout << "Enter the value of F : ";
    getline(cin, f);
    cout << "Enter the value of G : ";
    getline(cin, g);

    int l = e.length();
    for (int i = 0; i < l; i++)
    {
        cout << hex << uppercase << conditionalF(hexCharToInt(e[i]), hexCharToInt(f[i]), hexCharToInt(g[i]));
    }
}