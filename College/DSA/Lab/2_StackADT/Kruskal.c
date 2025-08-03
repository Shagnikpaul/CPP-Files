#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d \tINF\n", i);
        } else {
            printf("%d \t%d\n", i, dist[i]);
        }
    }
}

// Function that implements Dijkstra's single-source shortest path algorithm
void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];     // The output array. dist[i] holds the shortest distance from src to i
    int sptSet[MAX];   // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int V = 5; // Sample graph with 5 vertices
    int graph[MAX][MAX] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0; // Starting from vertex 0 as the source
    printf("Dijkstra's shortest path from source %d:\n", source);
    dijkstra(graph, source, V);

    return 0;
}