#include <iostream>
#include "map"
using namespace std;
int main()
{
    map<int, string> jokes;
    jokes[1] = "HAHAHAHA";
    jokes[2] = "LMAO";
    jokes[78] = "Whta";

    /*
    O(log n) complexity

    */

    // this will be sorted automatically...

    jokes.insert({5, "LOL"});
    for (auto i : jokes)
    {
        cout << i.second << " ";
    }
    cout << endl;

    // count  keys jokes.count(2) -> returns 1 else 0 if not found
    // remove 1 element jokes.erase(<key_value>)
}