#include <iostream>
using namespace std;
int main()
{
    int i, j;
    cout << "Enter 4 elements" << endl;
    int list[2][2];
    int  k = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << "Enter element no. " << k << " : ";
            k++;
            cin >> list[i][j];
        }
    }
    bool flag = true;
    for (i = 0; i < 2; i++)
    {
        if (flag) // [i][j]
        {
            flag = false;
            for (j = 0; j < 2; j++)
            {
                cout << list[j][i];
            }
        }
        else
        {
            flag = true;
            for (j = 1; j >= 0; j--)
            {
                cout << list[j][i];
            }
        }
    }
}