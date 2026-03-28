#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
    string inp;
    cout << "Enter the message in string format : ";
    getline(cin, inp);
    int k = 0;
    int j = 0;
    int startP = 1;
    int msgLen = inp.length() * 8; // in bits
    stringstream ss;
    ss << hex << setw(16) << setfill('0') << msgLen;
    string hexStr = ss.str();

    for (int i = 0; i < 16; i++)
    {
        for (; j < 4; j++)
        {
            if (k < inp.length())
            {
                cout << uppercase << hex << (int)inp[k++] << " ";
            }
            else
            {
                break;
            }
        }
        if (j >= 4)
        {
            j = 0;
            cout << endl;
        }

        if (startP && k >= inp.length())
        {
            startP = 0;
            cout << hex << 128 << " "; // print 80
            j++;
        }
        if (i <= 13 && k >= inp.length())
        {
            for (; j < 4; j++)
            {
                cout << "00 ";
            }
        }
    }

    k = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << hexStr[k] << hexStr[k + 1] << " ";
            k += 2;
        }
        cout << endl;
    }
}