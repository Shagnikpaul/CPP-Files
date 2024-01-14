#include <iostream>
using namespace std;



inline int max(int &a, int &b)
{
    return (a > b) ? a : b;
}
/*
    Has advantages and disadvantages.... 
    Read the following article for more info...

    https://www.geeksforgeeks.org/inline-functions-cpp/

*/



int main()
{
    int a = 2, b = 3;
    int ans  = max(a,b);
    cout << ans;
}