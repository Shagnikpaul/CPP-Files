#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
int main()
{
    string msg;
    getline(cin, msg);

    int l = msg.length() * 8;
    stringstream ss;
    ss << setw(16) << setfill('0') << hex << l;
    cout << "msg ln : " << ss.str() << endl;
    int c = 0;
    for (int i = 0; i < msg.length(); i++)
    {
        if (c == 4)
        {
            c = 0;
            cout << "\n";
        }
        cout << hex << (int)msg[i] << " ";
        c++;
    }
}