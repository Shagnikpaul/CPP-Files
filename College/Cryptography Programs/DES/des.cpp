#include<iostream>
#include<bitset>
#include<string>

using namespace std;

void leftRotate(bitset<28>& b) {
    bool msb = b[27];      
    b <<= 1;               
    b[0] = msb;            
}

bitset<48> D_box_1(const bitset<56>& key56) {
    static const int PC2[48] = {
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };

    bitset<48> roundKey;

    for (int i = 0; i < 48; i++) {
        int desPos = PC2[i];        
        int bitsetIndex = 56 - desPos;
        roundKey[47 - i] = key56[bitsetIndex];
    }

    return roundKey;
}

bitset<48> D_box_2(const bitset<56>& key56) {
    static const int PC2[48] = {
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };

    bitset<48> rk;

    for (int i = 0; i < 48; i++) {
        int desPos = PC2[i];          
        rk[47 - i] = key56[56 - desPos];
    }

    return rk;
}


int main(){
    cout << "Enter Cipher Key (16 hex chars): ";
    string hexKey;
    cin >> hexKey; 
    unsigned long long key = stoull(hexKey, nullptr, 16);
    bitset<64> cipher_key_64(key);

    bitset<56> cipher_key_56;
    int count=55;
    for (int i=63;i>=0;i--) {
        if(i%8!=0){
            cipher_key_56[count--]=cipher_key_64[i];
        }
    }
    for(int i=0;i<16;i++){
        bitset<28> Left,Right;
        for(int j=63;j>=28;j--){
            Left[63-j]=cipher_key_56[j];
        }
        for(int j=27;j>0;j--){
            Right[27-j]=cipher_key_56[j];
        }
        leftRotate(Left);
        leftRotate(Right);

    }
    cout << endl;

}