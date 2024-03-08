/*
In shallow copy, an object is created by simply copying the data of all variables of the original object. This works well if none of the variables of the object are defined in the heap section of memory. If some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location.
This will create ambiguity and run-time errors, dangling pointer. Since both objects will reference to the same memory location, then change made by one will reflect those change in another object as well. Since we wanted to create a replica of the object, this purpose will not be filled by Shallow copy.

*/

/*
DIF between shallow and deep
https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/?ref=next_article

*/

#include <iostream>
using namespace std;

class ABC
{

public:
    int a, b, c;
    ABC()
    {
        a = b = c = 0;
        cout << "Constructor callled " << endl;
    }
    ABC(const ABC &abc)
    {
        cout << "Copy Constructor called " << endl;
    }
};

class PQR
{
    int a, b, c;

public:
    void init(int p, int q, int r)
    {
        a = p;
        b = q;
        c = r;
    }

    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
};

int main()
{
    ABC a;
    ABC b = a;

    PQR p1, p2;
    p1.init(1, 2, 3);

    // When copying the data of object
    // after initialization then the
    // copy is done through DEFAULT
    // ASSIGNMENT OPERATOR
    p2 = p1; // only constructor will run

    // When copying the data of object
    // at the time of initialization
    // then copy is made through
    // COPY CONSTRUCTOR
    PQR p3 = p1; // only copy constructor will run...
}