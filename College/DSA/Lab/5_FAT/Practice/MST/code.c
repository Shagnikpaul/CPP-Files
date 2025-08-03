#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 99999;

typedef struct MinHeap
{
    int *A;
    int max_size;
    int size;
} MinHeap;


MinHeap * init_MinHeap(int max_size);
void read_inputMinHeap(MinHeap *Q, int n);
void buildMinHeap(MinHeap *Q);
void minHeapify(MinHeap *Q, int index);
int extractMin(MinHeap *Q);
int MST(int N, int Adj[N][N]);




int main(){
    int N,E;
    scanf("%d\n",&N);
    scanf("%d\n",&E);
    int Adj[N][N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Adj[i][j] = 0;
        }
    }
    
    for(int i=1;i<=E;i++){
        int i,j,k;
        scanf("%d, %d, %d",&i,&j,&k);
        Adj[i][j] = k;
        Adj[j][i] = k;
    }
    
    // printf("Adjacency Matrix : \n");
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d ",Adj[i][j]);
    //     }
    //     printf("\n");
    // }
    
    
    int x = MST(N, Adj);
    printf("%d\n",x);
    return 0;
}



void bottomUpHeapify(MinHeap *Q, int index){
    if(index > Q->size){
        return;
    }
    int parent = (index)/2;
    if(parent >= 1){
        if(Q->A[index] < Q->A[parent]){
            int t = Q->A[index];
            Q->A[index] = Q->A[parent];
            Q->A[parent] = t;
            bottomUpHeapify(Q, parent);
        }
    }
}






int MST(int N, int Adj[N][N]){
    
    MinHeap* Q;
    Q = init_MinHeap(N+1);
    read_inputMinHeap(Q, N);
    buildMinHeap(Q);
    
    int totalCost = 0;
    
    while(Q->size != 0){
        int min = extractMin(Q);
        printf("min = %d\n",min);
        totalCost += min;
        for(int i = 0;i<N;i++){
            if((Adj[min][i] != 0) && (Adj[min][i] < Q->A[i+1])){
                Q->A[i+1] = Adj[min][i];
                bottomUpHeapify(Q, (i+1));
            }
        }
    }
    
    return totalCost;
}

MinHeap * init_MinHeap(int max_size)
{
    MinHeap *Q;
    Q = malloc(sizeof(MinHeap));
    if(Q==NULL)
        return NULL;
    Q->A = malloc(sizeof(int) * max_size);
    if(Q->A == NULL)
    {
        free(Q);
        return NULL;
    }
    Q->A[0] = -999; // default value at index 0; start index from 1
    Q->max_size = max_size;
    Q->size = 0;
    return Q;
}

void read_inputMinHeap(MinHeap *Q, int n)
{
    for(int i=2;i<=n;i++){
        Q->A[i] = INF;
    }
    Q->A[1] = 0;
    Q->size = n;
}

// Complete the code of buildMinHeap
void buildMinHeap(MinHeap *Q)
{
    for(int i = floor(Q->size / 2); i>=1;i--){
        minHeapify(Q, i);
    }    
}


// Complete the code of minHeapify
void minHeapify(MinHeap *Q, int index)
{
    int left = 2 * index;
    int right = 2* index + 1;
    int smallest = -1;
    if(left <= Q->size && Q->A[left] < Q->A[index]){
        smallest = left;
    }
    else {
        smallest = index;
    }
    
    if(right <= Q->size && Q->A[right] < Q->A[smallest]){
        smallest = right;
    }
    
    if(smallest != index){
        int t = Q->A[index];
        Q->A[index] = Q->A[smallest];
        Q->A[smallest] = t;
        minHeapify(Q, smallest);
    }
}


// complete code of extractMin
int extractMin(MinHeap *Q)
{   
    int deleted_element = -9999;
    // fill your code here
    
    deleted_element = Q->A[1];
    
    Q->A[1] = Q->A[Q->size];
    Q->size--;
    minHeapify(Q,1);
    return deleted_element;

    
}