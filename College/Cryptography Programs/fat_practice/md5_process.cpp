#include <iostream>
using namespace std;

int lSh(int x, int t)
{
    return ((x << t) | (x >> (4 - t))) & 0xF;
}

int main()
{
    int a, b, c, d, m0, m1, t0, t1, nlp;
    cout << "a : ";
    cin >> hex >> a;
    cout << "b : ";
    cin >> hex >> b;
    cout << "c : ";
    cin >> hex >> c;
    cout << "d : ";
    cin >> hex >> d;

    string s;

    cout << "m0: ";
    cin >> s;
    m0 = stoi(s, nullptr, 2);

    cout << "m1: ";
    cin >> s;
    m1 = stoi(s, nullptr, 2);

    cout << "t0: ";
    cin >> s;
    t0 = stoi(s, nullptr, 2);

    cout << "t1: ";
    cin >> s;
    t1 = stoi(s, nullptr, 2);

    int p;
    cout << "mod : ";
    cin >> dec >> p;

    nlp = (b & c) | (~b & d);
    int x = (a + nlp + m0 + t0) % p;
    int y = lSh(x, 1);
    int z = (b + y) % p;

    cout << "nlp : " << nlp << "x : " << x << "y : " << y << "z : " << z << endl;
}