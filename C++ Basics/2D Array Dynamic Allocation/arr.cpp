#include <iostream>
using namespace std;
int main()
{
    cout << "Hello " << endl;
    int **arr = new int *[5]; // no of rows

    for (int i = 0; i < 5; i++)
    {
        arr[i] = new int[5]; // 5 columns in each row
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = 0;
        }
    }

    cout << "Created with zeros 5x5 " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Wanna clear memory ? 0 for no and other number for yes" << endl;

    int ex;
    cin >> ex;

    if (ex)
    {
        for (int i = 0; i < 5; i++)
        {
            delete[] arr[i];
        }
        cout << "Deleted... " << endl;
    }
}