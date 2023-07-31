#include <iostream>
using namespace std;

bool isP(char ch[], int size)
{
    int c=0,s = 0,e = size-1;

    while(s<=e)
    {
        if(ch[s] != ch[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}

char toLC(char ch)
{
    if (ch <= 'z' && ch >= 'a')
    {
        return ch;
    }
    else
    {
        return ((char)(ch + 32));
    }
}

int getLength(char ch[])
{
    int c = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        c++;
    }
    return c;
}

bool isAlpha(char ch)
{
    if (ch >= 65 && ch <= 90)
    {
        return true;
    }
    else if (ch >= 97 && ch <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char nch[90];
    int k = 0;
    char ch[90];
    cout << "Enter something : ";
    cin >> ch;
    int n = getLength(ch);
    for (int i = 0; i < n; i++)
    {
        if (isAlpha(ch[i]))
        {
            nch[k++] = toLC(ch[i]);
        }
    }
    nch[k] = '\0';
    cout << "Filtered String is : ";
    for (int j = 0; j < k; j++)
    {
        cout << nch[j];
    }
    cout << endl;
    cout << "Is it pallindrome ?  " << isP(nch, getLength(nch)) << endl;
}
