#include <iostream>
using namespace std;
int main()
{
    int m;
    cout << "m: ";
    cin >> m;
    int p = ((-m - 64) % 512) + 512;
    cout << "p = " << p << endl;
    cout << "msg ln = " << (p + 64 + m) << endl;
    cout << "b = " << (p + 64 + m) / 512 << endl;
}