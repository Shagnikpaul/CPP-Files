#include <iostream>
using namespace std;

int main()
{
    int p, g, xA, xB, xE;
    cout << "Enter prime number (p): ";
    cin >> p;
    cout << "Enter generator (g): ";
    cin >> g;
    cout << "Enter random number for Party A (xA): ";
    cin >> xA;
    cout << "Enter random number for Party B (xB): ";
    cin >> xB;
    cout << "Enter random number for Man-in-the-Middle (E): ";
    cin >> xE;
    int pubA = 1;
    for (int i = 0; i < xA; i++)
        pubA = (pubA * g) % p;
    int pubB = 1;
    for (int i = 0; i < xB; i++)
        pubB = (pubB * g) % p;
    int pubE = 1;
    for (int i = 0; i < xE; i++)
        pubE = (pubE * g) % p;
    cout << "\nPublic Key of A: " << pubA;
    cout << "\nPublic Key of B: " << pubB;
    cout << "\nPublic Key of E: " << pubE;

    int keyA = 1;
    for (int i = 0; i < xA; i++)
        keyA = (keyA * pubE) % p;
    int keyB = 1;
    for (int i = 0; i < xB; i++)
        keyB = (keyB * pubE) % p;
    int keyEA = 1;
    for (int i = 0; i < xE; i++)
        keyEA = (keyEA * pubA) % p;

    int keyEB = 1;
    for (int i = 0; i < xE; i++)
        keyEB = (keyEB * pubB) % p;

    cout << "\n\nSymmetric Key calculated by A (with E): " << keyA;
    cout << "\nSymmetric Key calculated by B (with E): " << keyB;
    cout << "\n\nE's Symmetric Key with A: " << keyEA;
    cout << "\nE's Symmetric Key with B: " << keyEB;
    return 0;
}