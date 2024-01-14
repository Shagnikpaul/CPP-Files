#include <iostream>
using namespace std;

void upd(int& x)
{
    x++;
}






int main()
{
    int i = 6;

    // reference variable
    int &j = i; 
    cout << j << endl;
    j++;
    cout << "After j++ , value of i is " << i << endl;
    upd(j);
    cout << "After upd(j), i is " << i <<endl;


    // imp when declaring new array using user input size we gotta initialize the array from heap memory (large pool) and not from stack
    // for allocating from heap we use "new" keyword

    cout << "Enter size of the array " << endl;
    int  n;
    cin >> n; 
    char* ch = new char[n];
    
    
    // and not char ch[n] which creates from stack memory and has chances of overflow...
    cout << "Created " << endl;
}