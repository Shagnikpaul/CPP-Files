
/*

Example 1:

Input:
5 (N)

9 (max range of elements)
4, 1, 3, 9, 7 (Array Elements)
Output:
1, 3, 4, 7, 9 (Sorted Array)

Example 2:

Input:
10

10 

10, 9, 8, 7, 6, 5, 4, 3, 2, 1

Output:
1, 2, 3, 4, 5, 6, 7, 8, 9, 10

*/

#include <stdio.h>

void countingSort(int* arr, int n, int k);

int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d, ",&arr[i]);
    }
    countingSort(arr,n,k);
    for(int i=0;i<n;i++){
        if(i!=(n-1))
        printf("%d, ",arr[i]);
        else
        printf("%d\n",arr[i]);
    }
    return 0;
}


void countingSort(int* arr, int n, int k){
    int aux[k+1];
    int ans[n];
    
    for(int i=0;i<k+1;i++){
        aux[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        aux[arr[i]]++;
    }
    for(int i=1;i<k+1;i++){
        aux[i] = aux[i-1] + aux[i];
    }
    
    for(int i=n-1;i>=0;i--){
        ans[aux[arr[i]] - 1] = arr[i];
        aux[arr[i]]--;
    }
    
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}
