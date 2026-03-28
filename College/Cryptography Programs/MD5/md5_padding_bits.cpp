#include <iostream>
using namespace std;
int main()
{
    int m;
    cout << "Enter the message length: ";
    cin >> m;
    int pBits = 512 - ((m + 64) % 512);
    cout << "Padding bits : " << pBits << endl;
    cout << "Total Message length " << (pBits + m + 64) << endl;
    cout << "Total Blocks needed " << ((pBits + m + 64) / 512) << endl;
}