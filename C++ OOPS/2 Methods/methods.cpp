#include <iostream>
using namespace std;

class Club
{
    int id;

public:
    // like interfaces in java
    void joe();

    void yipee()
    {
        cout << "YOOOOOOOOO " << endl;
    }
};

/*/

Defining functions outside a class but with predefined type

*/

void Club::joe()
{
    cout << "JOE " << endl;
}

int main()
{
    Club c1;
    c1.joe();
    c1.yipee();
}