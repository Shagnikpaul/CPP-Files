#include <iostream>
using namespace std;
int main()
{
    int hashmap[21] ={0};

    int max_element;

    int elements[] = {1,5,2,3,4,5,3,3,3,3,3,3,3,3,20,18,12,12};    


    for(int i=0;i<sizeof(elements)/sizeof(elements[0]); i++)
    {
        
        hashmap[elements[i]] ++;
    }


    cout << "count of 3 in the given list is " << hashmap[3] << endl;
    cout << "count of 0 in the given list is " << hashmap[0] << endl;
}