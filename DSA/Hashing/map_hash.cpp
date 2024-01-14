#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int,int> freq;

    int arr[] = {1,2,2,3,4,5,6,7,8,9,4,3,5,7,5,4,3};


    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {

        freq[arr[i]]++;
    }

    cout << "Count of 3 in the given list is " << freq[3] << endl;


}


/*

unordered_map

best case O(1)

worst case O(N)

*/