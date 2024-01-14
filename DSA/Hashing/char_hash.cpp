#include <iostream>
using namespace std;
int main()
{
    char str[] = "abasjdbqkjbwdwwwwwwww";

    int hashMap[256] = {0}; // for all 256 characters....

    for(int i=0;i<sizeof(str)/sizeof(str[0]); i++)
    {
        hashMap[str[i]] ++;
    } 

    cout << "Count of w in the string is " << hashMap['w']<< endl;
}