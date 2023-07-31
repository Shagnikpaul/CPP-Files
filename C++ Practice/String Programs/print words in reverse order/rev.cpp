#include <iostream>
using namespace std;
int main()
{
    string s("hello how are you im fine thank you");
    int l = s.length();
    string nl("");
    string word("");
    bool flag = true;
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (flag)
            {
                flag = false;
                nl = nl + word;
            }
            else
            {
                nl = nl + " " + word;
            }
            word = "";
        }
        else
        {
            word = s[i] + word;
        }
    }

    cout << nl;
}