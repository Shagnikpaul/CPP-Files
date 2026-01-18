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

    /*
        - insert 'X' in between repeated characters
        - add 'X' at the end if odd length
    */

    string processedPT2;

    for (int i = 0; i <= processedPT.length() - 1; i = i + 2)
    {
        processedPT2 += processedPT[i];
        if (processedPT[i] == processedPT[i + 1])
        {
            processedPT2 += 'X';
        }
        processedPT2 += processedPT[i + 1];
    }
    if (processedPT2.length() % 2 == 0)
    {
        processedPT2 += 'X';
    }

    cout << "After all the processing the plain text becomes : " << processedPT2;

    for (int i = 0; i <= processedPT2.length() - 1; i = i + 2)
    {
    }
    return 0;
}