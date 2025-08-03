#include<stdio.h>
#include<stdlib.h>
#include <math.h>
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
void addElement(MinHeap *Q, int x);
void Heapsort(MinHeap *Q);
void printHeap(MinHeap *Q);



int main()
{
    MinHeap *Q;
    int choice=0, max_size, n;
    int x;
    scanf("%d", &max_size);
    Q = init_MinHeap(max_size);
    n = scanf("%d", &n);
    n = (max_size / 2);
    //printf("max_size = %d\n",max_size);
    //printf("n = %d\n",n);
    read_inputMinHeap(Q, n);
    while(1)
    {   
        scanf("%d", &choice);
        //printf("Choice=%d\n", choice);
        // For initialization of link list
        if(choice==0)
        {
                init_MinHeap(max_size);
               
        }
        else if(choice ==1)
        {
            buildMinHeap(Q);
        }
        else if(choice==2)
        {      
               // printf("Enter the elements to be inserted \n");
                scanf("%d", &x);
                addElement(Q, x);
             
        }
        else if(choice==3)
        {
                x = extractMin(Q);
                printf("%d\n", x);
               
        }
        else if(choice==4)
        {
                printHeap(Q);
                
        }
        else if(choice ==5)
        {   
            Heapsort(Q);
            
        }
        else
            break;
    }
    return 0;
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

// complete code of this function
void read_inputMinHeap(MinHeap *Q, int n)
{
    for(int i=1;i<=n;i++){
        scanf("%d, ",&Q->A[i]);
    }
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

// printHeap
void printHeap(MinHeap *Q)
{
    for(int i=1;i<=Q->size;i++){
        if(i != (Q->size))
        printf("%d, ",Q->A[i]);
        else
        printf("%d\n",Q->A[i]);
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


void bottomUpHeapify(MinHeap *Q, int index){
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

// Write your code to add element into Heap here
void addElement(MinHeap *Q, int x)
{

    Q->size++;
    Q->A[Q->size] = x;
    bottomUpHeapify(Q, Q->size);
}

// Write your Heapsort code here ; you may use temprorary array to store deleted elements 
void Heapsort(MinHeap *Q)
{
    
}

