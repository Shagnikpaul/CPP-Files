#include <iostream>
#include <string>
using namespace std;

int cirLef(int x, int s)
{
    return ((x << s) | (x >> (4 - s))) & 0xF;
}

int main()
{
    int a, b, c, d;
    int m0, m1;
    int t0, t1;
    int s0, s1;
    int mod;
    string s;
    cout << "Enter value of register A : ";
    cin >> hex >> a;
    cout << "Enter value of register B : ";
    cin >> hex >> b;
    cout << "Enter value of register C : ";
    cin >> hex >> c;
    cout << "Enter value of register D : ";
    cin >> hex >> d;
    cout << "Enter the first part of the message : ";
    cin >> s;
    m0 = stoi(s, nullptr, 2);
    cout << "Enter the second part of the message : ";
    cin >> s;
    m1 = stoi(s, nullptr, 2);
    cout << "Enter the first constant : ";
    cin >> s;
    t0 = stoi(s, nullptr, 2);
    cout << "Enter the second constant : ";
    cin >> s;
    t1 = stoi(s, nullptr, 2);
    cout << "Enter the mod to be taken: ";
    cin >> dec >> mod;
    int nlp;
    int x, y, z;

    cout << "For round 1 - Step 1" << endl;
    nlp = (b & c) | (~b & d);
    /*
        for other rounds
        - (b and d) or (c and ~d)
        - b xor c xor d
        - c xor (b or ~d)
    */
    x = (nlp + a + m0 + t0) % mod;
    y = cirLef(x, 1);
    z = (y + b) % mod;
    // cout << "mod = " << mod << "\n";

    a = z;
    int t = d;
    d = c;
    c = b;
    b = a;
    a = t;
    cout << " nlp = " << nlp << " result x = " << x << " result of z = " << z << endl;
    cout << "Digest step 1: " << a << b << c << d << endl;
    cout << "For round 1 - Step 2" << endl;
    nlp = (b & c) | (~b & d);
    x = (nlp + a + m1 + t1) % mod;
    y = cirLef(x, 2);
    z = (y + b) % mod;
    // cout << "mod = " << mod << "\n";
    cout << " nlp = " << nlp << " result x = " << x << " result of z = " << z << endl;

    a = z;
    t = d;
    d = c;
    c = b;
    b = a;
    a = t;
    cout << "Digest step 2: " << a << b << c << d << endl;
}