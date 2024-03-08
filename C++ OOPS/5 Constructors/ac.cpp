#include <iostream>
using namespace std;


/*

Copy constructor takes a reference to an object of the same class as an argument. If you pass the object by value in the copy constructor, it would result in a recursive call to the copy constructor itself. This happens because passing by value involves making a copy, and making a copy involves calling the copy constructor, leading to an infinite loop. Using a reference avoids this recursion. So we use reference of Objects to avoid infinite calls.

*/


/*
Copy Constructor vs Assignment Operator in C++
https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/

*/


class ABC
{

public:
    int id;

    // declatation inside the class
public:
    ABC(int i)
    {
        id = i;
    }

    // declaration outside the class
    ABC(int j, int i);

    // copy constructor
    ABC(ABC& abc) {
        id = abc.id;
    }
};

ABC::ABC(int j, int i)
{
    id = i+j;
}

int main()
{
    ABC abc(2,3);
    ABC abc1(6);
    ABC abc3(abc);
    cout << abc.id << " " << abc1.id << " abc 3 = " << abc3.id;
}