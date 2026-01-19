#include <iostream>
using namespace std;
int main()
{
    int k = 3;
    string plainText = "";
    cout << "Enter the plain text : ";
    cin >> plainText;
    int len = plainText.length();
    string cipherText(len, ' '); // to prevent garbage values

    // convert all the lower case letters to upper case letters...
    for (int i = 0; i < len; i++)
    {
        char c = plainText[i];
        if (c >= 97 && c <= 122)
        {
            plainText[i] = plainText[i] - 97 + 65;
        }
    }

    /*
        Encryption Process
    */
    for (int i = 0; i < len; i++)
    {
        char c = plainText[i];
        if (c >= 65 && c <= 91)
        {
            cipherText[i] = ((plainText[i] - 'A') + 3) % 26 + 'A';
        }
        else
        {
            // ignore characters other than letters...
            cipherText[i] = plainText[i];
        }
    }
    cout << "Cipher text generated after encryption : " << cipherText << endl;

    string decryptedPlainText(len, ' ');
    /*
        Decryption Process
    */
    for (int i = 0; i < len; i++)
    {
        char c = cipherText[i];
        if (c >= 65 && c <= 91)
        {
            decryptedPlainText[i] = ((cipherText[i] - 'A') - 3) % 26 + 'A';
        }
        else
        {
            // ignore characters other than letters...
            decryptedPlainText[i] = cipherText[i];
        }
    }

    cout << "Plain text generated after decryption : " << decryptedPlainText << endl;
}