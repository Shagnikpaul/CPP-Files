#include <iostream>
using namespace std;

int main()
{
    string plainText;
    string key;
    cout << "Enter the plain text: ";
    cin >> plainText;
    cout << "Enter the key (consisting only of upper case letters) : ";
    cin >> key;

    int hash[26] = {0};
    char keyMatrix[5][5];
    int ind = 0, ind2 = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            while (ind < key.length() && hash[key[ind] - 'A'] != 0)
            {
                ind++;
            }
            if (ind < key.length())
            {
                hash[key[ind] - 'A'] = 1;
                if (key[ind] - 'A' == 'I')
                {
                    hash['J'] = 1;
                }
                keyMatrix[i][j] = key[ind];
                ind++;
            }
            else
            {
                while (hash[ind2] != 0 || 'A' + ind2 == 'J')
                {
                    ind2++;
                }
                keyMatrix[i][j] = 'A' + ind2++;
            }
        }
    }
    int row[26];
    int col[26];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            row[keyMatrix[i][j] - 'A'] = i;
            col[keyMatrix[i][j] - 'A'] = j;
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // fixing I/J as same cell in the matrix...
    row['J' - 'A'] = row['I' - 'A'];
    col['J' - 'A'] = col['I' - 'A'];

    /*
        plain - text pre-processing :
        - remove spaces
        - remove special characters
        - all uppercase letters
        - insert 'X' in between repeated characters
        - add 'X' at the end if odd length
    */

    string processedPT;
    /*
        - remove spaces
        - remove special characters
        - all uppercase letters
    */
    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 97 && plainText[i] <= 122)
        {
            processedPT += plainText[i] - 'a' + 'A';
        }
        else if (plainText[i] >= 65 && plainText[i] <= 90)
        {
            processedPT += plainText[i];
        }
    }
    cout << "Stage 1 processing plain text : " << processedPT << endl;
    /*
        - insert 'X' in between repeated characters
        - add 'X' at the end if odd length
    */

    string processedPT2;

    for (int i = 0; i < processedPT.length();)
    {
        processedPT2 += processedPT[i];
        if (i + 1 < processedPT.length())
        {
            if (processedPT[i] == processedPT[i + 1])
            {
                processedPT2 += 'X';
                i++;
            }
            else
            {
                processedPT2 += processedPT[i + 1];
                i += 2;
            }
        }
        else
        {
            i++;
        }
    }
    if (processedPT2.length() % 2 != 0)
    {
        processedPT2 += 'X';
    }

    cout << "Stage 2 processing plain text : " << processedPT2 << endl;

    // encryption

    string cipherText = "";
    for (int i = 0; i < processedPT2.length() - 1; i = i + 2)
    {
        int r1 = row[processedPT2[i] - 'A'];
        int r2 = row[processedPT2[i + 1] - 'A'];
        int c1 = col[processedPT2[i] - 'A'];
        int c2 = col[processedPT2[i + 1] - 'A'];

        if (r1 == r2)
        {
            cipherText += (char)keyMatrix[r1][(c1 + 1) % 5];
            cipherText += (char)keyMatrix[r1][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            cipherText += (char)keyMatrix[(r1 + 1) % 5][c2];
            cipherText += (char)keyMatrix[(r2 + 1) % 5][c2];
        }
        else
        {
            cipherText += (char)keyMatrix[r1][c2];
            cipherText += (char)keyMatrix[r2][c1];
        }
    }
    cout << "After encryption process the cipher text we get : " << cipherText << endl;

    // decryption ...
    string decryptedPlainText = "";
    for (int i = 0; i < cipherText.length() - 1; i = i + 2)
    {
        int r1 = row[cipherText[i] - 'A'];
        int r2 = row[cipherText[i + 1] - 'A'];
        int c1 = col[cipherText[i] - 'A'];
        int c2 = col[cipherText[i + 1] - 'A'];

        if (r1 == r2)
        {
            decryptedPlainText += (char)keyMatrix[r1][(c1 - 1) % 5 + ((c1 - 1) % 5 < 0 ? 5 : 0)];
            decryptedPlainText += (char)keyMatrix[r1][(c2 - 1) % 5 + ((c2 - 1) % 5 < 0 ? 5 : 0)];
        }
        else if (c1 == c2)
        {

            decryptedPlainText += (char)keyMatrix[(r1 - 1) % 5 + ((r1 - 1) % 5 < 0 ? 5 : 0)][c2];
            decryptedPlainText += (char)keyMatrix[(r2 - 1) % 5 + ((r2 - 1) % 5 < 0 ? 5 : 0)][c2];
        }
        else
        {
            decryptedPlainText += (char)keyMatrix[r1][c2];
            decryptedPlainText += (char)keyMatrix[r2][c1];
        }
    }
    string finalDecryptedPlainText = "";
    for (char x : decryptedPlainText)
    {
        if (x != 'X')
            finalDecryptedPlainText += x;
    }
    cout << "After decryption process the final plain text we get : " << finalDecryptedPlainText << endl;
    return 0;
}