#include <iostream>
using namespace std;
int main()
{
    int list[2][2];
    cout << "Enter 4 elements" << endl;

    int i, j,k=0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << "Enter element no. " << k << " : "; 
            k++;
            cin >> list[i][j];
        }
    }

    
}