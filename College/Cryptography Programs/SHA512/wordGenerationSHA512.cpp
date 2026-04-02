#include <iostream>
#include <iomanip>
using namespace std;

unsigned int cirRight16(unsigned int x, unsigned int s)
{
    s %= 16;
    return ((x >> s) | (x << (16 - s))) & 0xFFFF;
}

int rotShif(int x, int l, int m, int n)
{
    l %= 16;
    m %= 16;
    n %= 16;
    return cirRight16(x, l) ^ cirRight16(x, m) ^ (x >> n);
}

int main()
{
    int w_i_16, w_i_15, w_i_7, w_i_2;
    cout << "Enter the word number to generated : ";
    int i;
    cin >> i;
    cout << "Enter the word[" << (i - 16) << "] : ";
    cin >> hex >> w_i_16;
    cout << "Enter the word[" << (i - 15) << "] : ";
    cin >> hex >> w_i_15;
    cout << "Enter the word[" << (i - 7) << "] : ";
    cin >> hex >> w_i_7;
    cout << "Enter the word[" << (i - 2) << "] : ";
    cin >> hex >> w_i_2;

    int w_i;
    w_i = (w_i_16 + rotShif(w_i_15, 1, 8, 7) + w_i_7 + rotShif(w_i_2, 19, 61, 6)) & 0xFFFF;
    cout << "W" << i << " = " << hex << uppercase << w_i << setw(4) ;
}