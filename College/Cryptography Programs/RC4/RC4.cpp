#include<iostream>

using namespace std;

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int plainText[]={1,17,12,20};
    int key[]={1,2,2,2};
    const int stateVector=8;

    int S[stateVector];
    int K[stateVector];
    //initialization
    for(int i=0;i<stateVector;i++){
        S[i]=i;
        K[i]=key[i%size(key)];
    }
    printArr(S,stateVector);
    printArr(K,stateVector);

    //permutation
    int j=0;
    for(int i=0;i<stateVector;i++){
        int result = (j + S[i] + K[i]) % stateVector;
        cout<<"i="<<i<<"  j="<<j<<endl;
        cout << j << " + " << S[i] << " + " << K[i]
            << " = " << (j + S[i] + K[i])
            << " % " << stateVector
            << " = " << result << " (swap) " << i << "," << result<< endl;


        j = result;
        
        swap(S[i],S[j]);
        
        printArr(S,stateVector);
        cout<<endl<<endl;
    }
    printArr(S,stateVector);

    //Encryption
    int cipherText[stateVector];
    int i=0;
    j=0;
    for (int k = 0; k < sizeof(plainText)/sizeof(plainText[0]); k++) {

    // i calculation
    int old_i = i;
    i = (i + 1) % stateVector;
    cout << "i = (" << old_i << " + 1) % " << stateVector
         << " = " << i << endl;

    // j calculation
    int old_j = j;
    j = (j + S[i]) % stateVector;
    cout << "j = (" << old_j << " + S[" << i << "]=" << S[i]
         << ") % " << stateVector
         << " = " << j << endl;

    // swap S[i] and S[j]
    swap(S[i], S[j]);
    cout << "After swap S[" << i << "] and S[" << j << "]: ";
    for (int x = 0; x < stateVector; x++)
        cout << S[x] << " ";
    cout << endl;

    // temp calculation
    int index = (S[i] + S[j]) % stateVector;
    int temp = S[index];
    cout << "temp = S[(S[" << i << "]=" << S[i]
         << " + S[" << j << "]=" << S[j]
         << ") % " << stateVector
         << "] = S[" << index << "] = "
         << temp << endl;

    // encryption
    cipherText[k] = plainText[k] ^ temp;

    cout << "----------------------------------" << endl;
}

    printArr(cipherText,size(plainText));





    // Decryption
cout << "\n===== DECRYPTION =====\n";

// Reinitialize S and K (important!)
for(int i=0;i<stateVector;i++){
    S[i] = i;
    K[i] = key[i % size(key)];
}

// Repeat KSA
j = 0;
for(int i=0;i<stateVector;i++){
    j = (j + S[i] + K[i]) % stateVector;
    swap(S[i], S[j]);
}

// PRGA for decryption
int decryptedText[stateVector];
i = 0;
j = 0;

for (int k = 0; k < size(plainText); k++) {

    // i calculation
    int old_i = i;
    i = (i + 1) % stateVector;
    cout << "i = (" << old_i << " + 1) % " << stateVector
         << " = " << i << endl;

    // j calculation
    int old_j = j;
    j = (j + S[i]) % stateVector;
    cout << "j = (" << old_j << " + S[" << i << "]=" << S[i]
         << ") % " << stateVector
         << " = " << j << endl;

    // swap
    swap(S[i], S[j]);
    cout << "After swap S[" << i << "] and S[" << j << "]: ";
    printArr(S, stateVector);

    // temp calculation
    int index = (S[i] + S[j]) % stateVector;
    int temp = S[index];
    cout << "temp = S[(S[" << i << "]=" << S[i]
         << " + S[" << j << "]=" << S[j]
         << ") % " << stateVector
         << "] = S[" << index << "] = "
         << temp << endl;

    // decryption
    decryptedText[k] = cipherText[k] ^ temp;

    cout << "----------------------------------" << endl;
}

cout << "Decrypted Text: ";
printArr(decryptedText, size(plainText));

    return 0;
}