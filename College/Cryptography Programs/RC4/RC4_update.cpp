#include <iostream>
using namespace std;

int main() {
    const int textSize = 4;
    const int keySize = 4;

    int stateVector;
    cout << "Enter state vector size: ";
    cin >> stateVector;

    int plainText[textSize];
    cout << "Enter 4 plaintext values: ";
    for(int i = 0; i < textSize; i++)
        cin >> plainText[i];

    int key[keySize];
    cout << "Enter 4 key values: ";
    for(int i = 0; i < keySize; i++)
        cin >> key[i];

    int S[stateVector];
    int K[stateVector];

    for(int i = 0; i < stateVector; i++){
        S[i] = i;
        K[i] = key[i % keySize];
    }

    int j = 0;
    for(int i = 0; i < stateVector; i++){
        j = (j + S[i] + K[i]) % stateVector;
        swap(S[i], S[j]);
    }

    int cipherText[textSize];
    int i = 0;
    j = 0;

    for(int k = 0; k < textSize; k++){
        i = (i + 1) % stateVector;
        j = (j + S[i]) % stateVector;
        swap(S[i], S[j]);
        int temp = S[(S[i] + S[j]) % stateVector];
        cipherText[k] = plainText[k] ^ temp;
    }

    cout << "\nCipher Text: ";
    for(int k = 0; k < textSize; k++)
        cout << cipherText[k] << " ";
    cout << endl;

    for(int x = 0; x < stateVector; x++){
        S[x] = x;
        K[x] = key[x % keySize];
    }

    j = 0;
    for(int x = 0; x < stateVector; x++){
        j = (j + S[x] + K[x]) % stateVector;
        swap(S[x], S[j]);
    }

    int decryptedText[textSize];
    i = 0;
    j = 0;

    for(int k = 0; k < textSize; k++){
        i = (i + 1) % stateVector;
        j = (j + S[i]) % stateVector;
        swap(S[i], S[j]);
        int temp = S[(S[i] + S[j]) % stateVector];
        decryptedText[k] = cipherText[k] ^ temp;
    }

    cout << "Decrypted Text: ";
    for(int k = 0; k < textSize; k++)
        cout << decryptedText[k] << " ";

    return 0;
}