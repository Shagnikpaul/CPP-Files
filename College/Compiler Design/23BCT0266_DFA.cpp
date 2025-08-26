
/*
23BCT0266

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isAccepted(const string &s)
{
    int len = s.length();
    if (len == 1 && s[0] == 'a')
        return true;
    if (len == 3 && s[0] == 'a' && s[1] == 'b' && s[2] == 'b')
        return true;
    int i = 0;
    while (i < len && s[i] == 'a')
        i++;
    if (i == len - 1 && s[i] == 'b')
        return true;
    return false;
}

int main()
{
    cout << "\n\n \t\t\t ---------23BCT0266-------\n\n";
    ifstream file("dfatestcases.txt");
    string s;
    while (getline(file, s))
    {
        if (isAccepted(s))
            cout << "String: " << s << " accepted" << endl;
        else
            cout << "String: " << s << " not accepted" << endl;
    }
    return 0;
}