#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int x = 4;

    double b = static_cast<double>(x) / 1.0;
    cout << fixed << setprecision(2) << b;
}