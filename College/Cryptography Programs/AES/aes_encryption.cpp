#include <string>
#include <iostream>

using namespace std;
void printHex(int x)
{
    const char *hex = "0123456789ABCDEF";
    cout << hex[(x >> 4) & 0xF] << hex[x & 0xF];
}
int main()
{
    string plainText;
    cout << "Enter the plain text in hexadecimal format without the \"0x\" part : ";
    cin >> plainText;
    int in = 0;
    int pt_state_matrix[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pt_state_matrix[i][j] = stoi(plainText.substr(in, 2), nullptr, 16); // hex digit
            in += 2;
        }
    }
    cout << "plaintext state matrix : " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printHex(pt_state_matrix[j][i]);
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
