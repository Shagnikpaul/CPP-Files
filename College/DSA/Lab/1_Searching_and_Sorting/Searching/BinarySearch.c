#include "stdio.h"

int binarySearch(int * arr, int n, int x);


int main()
{
    //// write da code here...
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = -10;
    int result = binarySearch(arr, 10, target);
    if(result != -1) {
        printf("Target was found at index %d\n", result);
    }
    else {
        printf("Target %d was not found.\n",target);
    }
    


    return 0;
}


int binarySearch(int * arr, int n, int x){
    int start = 0;
    int target = x;
    int end = n - 1;
    int mid = (start+end)/2;
    while (start <= end)
    {
        /* code */
        if(arr[mid] == target){
            return mid;
        }

        else if(arr[mid] < target){
            start = mid + 1;
        }
        else {
            end =  mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}