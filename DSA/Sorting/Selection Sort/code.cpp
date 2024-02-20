#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3,0,-1,33,4,22,100};
    int n = 7;
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }

    for(int i=0;i<n;i++) 
    {
        cout << arr[i] << ", ";
    }
}