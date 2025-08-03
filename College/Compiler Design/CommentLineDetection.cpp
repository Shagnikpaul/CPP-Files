#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string s;

    ifstream file("code.txt");
    int i = 0;
    int wasCommment = 0;
    while (getline(file, s))
    {
        // cout << "Line " << i + 1 << ": " << s << endl;

        for (int j = 0; j < s.size(); j++)
        {
            // cout << "scanning " << s[j] << endl;
            if (s[j] == '/' && s[j + 1] == '/')
            {
                wasCommment = 1;
                cout << "Found a comment line of double forward slash '//' type at line no. " << (i + 1) << " and character number " << (j + 1) << endl;
                break;
            }

            if (s[j] == '/' && s[j + 1] == '*')
            {
                wasCommment = 1;
                cout << "Found start of multi-line comment  '/*' type at line no. " << (i + 1) << " and character number " << (j + 1) << endl;
            }

            if (s[j] == '*' && s[j + 1] == '/')
            {
                cout << "Found end of multi-line comment  '*/' type at line no. " << (i + 1) << " and character number " << (j + 1) << endl;
            }
        }
        if (!wasCommment)
        {
            cout << "Line no. " << i + 1 << " was not a comment line." << endl;
        }
        wasCommment = 0;
        i++;
    }
}

/*



*/