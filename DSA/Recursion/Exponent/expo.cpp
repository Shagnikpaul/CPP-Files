#include <iostream>
using namespace std;

int ex(int n, int e)
{
    if(e==0)
    {
        return 1;
    }
    
    if(e%2==0)
    {
        return ex(n,e/2)*ex(n,e/2);
    }
    else
    {
        return n*ex(n,e/2)*ex(n,e/2);
    }
}

int main()
{
    int n = 10;
    int ans = ex(n,2);
    cout << "Exponent is " << ans; 
}