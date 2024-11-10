#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int *arr;
    int max_size;
    int front;
    int back;
} Queue;


Queue *init(Queue *q, int max);
void enqueue(Queue *q, int x);
int dequeue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);


Queue *init(Queue *q, int max)
{
    q = malloc(sizeof(Queue));
    if (q == NULL)
    {
        return NULL;
    }

    q->arr = (int *)malloc(sizeof(int) * max);
    if (q == NULL)
    {
        free(q);
        return NULL;
    }

    q->front = -1;
    q->back = -1;
    q->max_size = max;
    return q;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue is full !!\n\n");
        return;
    }
    if (q->front == -1 && q->back == -1)
    {
        q->front = 0;
        q->back = 0;
        q->arr[q->back] = x;
        //printf("\nenqueued %d\n\n", q->arr[q->back]);
        return;
    }
    q->back++;
    q->arr[q->back] = x;
    //printf("\nenqueued %d\n\n", q->back);
}

int dequeue(Queue *q)
{

    if (isEmpty(q))
    {
        printf("Queue is already empty !!\n\n");
        return -1;
    }
    int a = q->arr[q->front];
    q->front++;
    return a;
}


int isFull(Queue *q)
{
    if ((q->back) == (q->max_size - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q)
{
    if (q->front > q->back)
    {
        return 1;
    }else{
    return 0;}
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty !!\n\n");
        return;
    }
    for (int i = q->front; i <= q->back; i++)
    {
        printf("%d, ", q->arr[i]);
    }
    printf("\n\n");
}


void BFS_traversal(int N, int Adj[N][N], int src);

int main(){
    int N,E;
    scanf("%d",&N);
    scanf("%d",&E);
    //printf("N = %d\n",N);
    //printf("E = %d\n",E);
    
    int Adj[N][N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Adj[i][j] = 0;
        }
    }
    
    
    for(int i=1;i<=E;i++){
        int m,n;
        scanf("%d, %d",&m,&n);
        Adj[m][n] = 1;
        Adj[n][m] = 1;
    }
    int src;
    scanf("%d",&src);
    // printf("src = %d\n",src);
    // printf("Adjacency Matrix : \n");
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d ",Adj[i][j]);
    //     }
    //     printf("\n");
    // }
    BFS_traversal(N,Adj, src);
    return 0;
}


void BFS_traversal(int N, int Adj[N][N], int src){
    // printf("Adjacency Matrix : \n");
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d ", Adj[i][j]);
    //     }
    //     printf("\n");
    // }
    
    int visited[N];
    int parent[N];
    int level[N];
    int order[N];
    int c = 0;
    Queue* Q;
    Q = NULL;
    Q = init(Q, N*10);
    //printf("Queue size is %d\n",Q->max_size);
    
    
    for(int i=0;i<N;i++){
        visited[i] = 0;
        parent[i] = -1;
        level[i] = -1;
    }
    
    visited[src] = 1;
    enqueue(Q, src);
    level[src] = 0;
    while(!isEmpty(Q)){
        int j = dequeue(Q);
        //printf("order  = %d\n",j);
        order[c++] = j;
        for(int i=0;i<N;i++){
            //printf("i = %d, j = %d and is %d\n",i,j,Adj[j][i]);
            int k = Adj[j][i]; 
            if(k){
                if(visited[i] == 0){
                    visited[i] = 1;
                    enqueue(Q, i);
                    parent[i] = j;
                    level[i] = level[j] + 1;
                }
            }
        }
        //display(Q);
    }
    
    for(int i=0;i<N;i++){
        if(i!=(N-1))
        printf("%d, ",order[i]);
        else
        printf("%d\n",order[i]);
        
    }
    for(int i=0;i<N;i++){
        if(i!=(N-1))
        printf("%d, ",level[order[i]]);
        else
        printf("%d\n",level[order[i]]);
    }
    for(int i=0;i<N;i++){
        if(i!=(N-1))
        printf("%d, ",parent[order[i]]);
        else
        printf("%d\n",parent[order[i]]);
    }

}