
/*
PUBLIC
All the class members declared under the public specifier will be available to everyone. The data members and member functions declared as public can be accessed by other classes and functions too. The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class.

Private: The class members declared as private can be accessed only by the member functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of the class.

Protected: The protected access modifier is similar to the private access modifier in the sense that it can’t be accessed outside of its class unless with the help of a friend class. The difference is that the class members declared as Protected can be accessed by any subclass (derived class) of that class as well.

*/

class DataCentre
{
private:
    int passId = 23;

public:
    char name[12];

protected:
    int alternateId = 34;

private:
    void changeId(int id)
    {
        passId = id;
    }
};

class JOE : public DataCentre
{
    public:
    void tomfoolery()
    {
        alternateId = 0;
    }
    /*
    this can access the parameter alternateID
    */
};

#include <iostream>
using namespace std;
int main()
{
    JOE k;
    k.tomfoolery();
}