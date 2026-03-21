#include <iostream>
using namespace std;

int main() {
    int p, g, xA, xB;

    cout << "Enter prime number (p): ";
    cin >> p;
    cout << "Enter generator (g): ";
    cin >> g;
    cout << "Enter random number for Party A (xA): ";
    cin >> xA;
    cout << "Enter random number for Party B (xB): ";
    cin >> xB;
    int pubA = 1;
    for(int i = 0; i < xA; i++)
        pubA = (pubA * g) % p;
    int pubB = 1;
    for(int i = 0; i < xB; i++)
        pubB = (pubB * g) % p;
    cout << "\nPublic Key of Party A: " << pubA;
    cout << "\nPublic Key of Party B: " << pubB;
    int symmetricKey = 1;
    for(int i = 0; i < xA; i++)
        symmetricKey = (symmetricKey * pubB) % p;
    cout << "\nSymmetric Key: " << symmetricKey;
    return 0;
}