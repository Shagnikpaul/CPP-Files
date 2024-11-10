#include <stdio.h>



void bubbleSort(int* arr, int n, int k);

int main(){
    int n;
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d, ",&arr[i]);
    }
    
    bubbleSort(arr, n, k);
    
    for(int i=0;i<n;i++){
        if(i!=(n-1))
        printf("%d, ",arr[i]);
        else 
        printf("%d\n",arr[i]);
    }
    return 0;
}


void bubbleSort(int* arr, int n, int k){
    for(int i=0;i<k;i++){
        for(int j = 0; j < (n-i-1);j++){
            if(arr[j+1] < arr[j]){
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
    }
}