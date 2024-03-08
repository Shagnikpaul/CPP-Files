/*
A friend class can access private and protected members of other classes in which it is declared as a friend. It is sometimes useful to allow a particular class to access private and protected members of other classes. For example, a LinkedList class may be allowed to access private members of Node.

We can declare a friend class in C++ by using the friend keyword.


*/
#include <iostream>
using namespace std;

class Admin;
class TOM
{
public:
    void newTomFoolery(Admin &a);
    /*
     When ever u declare a friend function in another class dnt write the definition inside a class it should be outside
    */
};

class Admin
{
public:
    char name[23];

private:
    int passId;

protected:
    int sessionToken;

public:
    Admin()
    {
        passId = 21;
        sessionToken = 233;
    }
    // friend class
    friend class JOE;

    // global function as friend function
    friend void joes(Admin &a);

    // friend function of another class but always first declare both the classes
    friend void TOM::newTomFoolery(Admin&);
};

void joes(Admin &a)
{
    cout << "In 1 vlaue " << a.sessionToken << endl;
}



class JOE
{
public:
    void tomFoolery(Admin &ad)
    {
        cout << "YOUR ID IS " << ad.passId << endl;
    }
};



void TOM::newTomFoolery(Admin& a)
{
    cout << "YOUR ID IS in the newTom " << a.passId << endl;
}

int main()
{
    JOE k;
    Admin a;
    k.tomFoolery(a);
    joes(a);
    TOM t;
    t.newTomFoolery(a);
}