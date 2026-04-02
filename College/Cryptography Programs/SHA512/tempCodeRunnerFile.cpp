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

int majority(int a, int b, int c)
{
    return ((a & b) ^ (b & c) ^ (c & a)) & 0xF;
}
int main()
{
    string a, b, c;
    cout << "Enter the value of A : ";
    getline(cin, a);
    cout << "Enter the value of B : ";
    getline(cin, b);
    cout << "Enter the value of C : ";
    getline(cin, c);

    int l = a.length();
    for (int i = 0; i < l; i++)
    {
        cout << hex << uppercase << majority(hexCharToInt(a[i]), hexCharToInt(b[i]), hexCharToInt(c[i]));
    }
}