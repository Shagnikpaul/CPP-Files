#include <iostream>
using namespace std;

void sayD(int n, string arr[])
{
    if(n==0) 
    return ;
    int d = n % 10;
    n = n / 10;
    sayD(n, arr);
    cout << arr[d];
}

int main()
{
    int n = 3420;
    string digitsAsWords[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayD(n, digitsAsWords);
}