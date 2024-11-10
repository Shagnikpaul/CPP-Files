#include <stdio.h>


void binarySearch(int* arr, int n,int key, int* ans);
int isSorted(int* arr, int n);

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d, ",&arr[i]);
    }
    int key;
    scanf("%d",&key);
    
    if(isSorted(arr, n)){
        int ans[2];
        ans[1] = 0;
        ans[0] = -1;
        binarySearch(arr, n, key, ans);
        printf("1\n");
        printf("%d\n",ans[0]);
        printf("%d\n",ans[1]);
    }
    else {
        printf("Error 405:: Wrong I/P");
        return 405;
    }
    
    return 0;
}


void binarySearch(int* arr, int n,int key, int* ans){
    int low = 0;
    int high = n - 1;
    int mid = (low+high)/2;
    
    // printf("arrya to be saerched \n");
    // for(int i=0;i<n;i++){
    //     printf("%d, ",arr[i]);
    // }
    
    // printf("\n");
    // printf("key  = %d\n",key);
    
    
    while(low <= high){
        
        ans[1]++;
        if(arr[mid] == key){
            ans[1]++;
            ans[0] = mid;
            return;
        }
        ans[1]++;
        if(arr[mid] < key){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        
        mid = (low+high)/2;
    }
    ans[0] = -1;
    return;
}


int isSorted(int* arr, int n){
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return 0;
        }
    }
    return 1;
}