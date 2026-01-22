#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>

using namespace std;

static const int PC1[56] = {
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
};

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

void leftRotate(bitset<28>& b, int shifts) {
    for (int s = 0; s < shifts; s++) {
        bool msb = b[27];
        b <<= 1;
        b[0] = msb;
    }
}

bitset<48> D_box(const bitset<56>& key56) {
    bitset<48> roundKey;
    for (int i = 0; i < 48; i++) {
        roundKey[47 - i] = key56[56 - PC2[i]];
    }
    return roundKey;
}

int main() {
    string hexKey;
    cout << "Enter Cipher Key (16 hex chars): ";
    cin >> hexKey;

    unsigned long long key = stoull(hexKey, nullptr, 16);
    bitset<64> key64(key);

    bitset<56> key56;
    for (int i = 0; i < 56; i++) {
        key56[55 - i] = key64[64 - PC1[i]];
    }

    bitset<28> C, D;
    for (int i = 0; i < 28; i++) {
        C[i] = key56[i + 28];
        D[i] = key56[i];
    }

    leftRotate(C, 1);
    leftRotate(D, 1);

    for (int i = 0; i < 28; i++) {
        key56[i] = D[i];
        key56[i + 28] = C[i];
    }

    bitset<48> K1 = D_box(key56);
    cout << "Round 1 Key: "
         << hex << setw(12) << setfill('0')
         << K1.to_ullong() << endl;

    leftRotate(C, 1);
    leftRotate(D, 1);

    for (int i = 0; i < 28; i++) {
        key56[i] = D[i];
        key56[i + 28] = C[i];
    }

    bitset<48> K2 = D_box(key56);
    cout << "Round 2 Key: "
         << hex << setw(12) << setfill('0')
         << K2.to_ullong() << endl;
}