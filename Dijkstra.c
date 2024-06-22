#include <stdio.h>
#include <limits.h>

#define V 7

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 2, INT_MAX, 3, INT_MAX, INT_MAX, INT_MAX},
        {2, 0, 5, INT_MAX, 4, INT_MAX, INT_MAX},
        {INT_MAX, 5, 0, INT_MAX, INT_MAX, 4, 3},
        {3, INT_MAX, INT_MAX, 0, 5, INT_MAX, INT_MAX},
        {INT_MAX, 4, INT_MAX, 5, 0, 2, INT_MAX},
        {INT_MAX, INT_MAX, 4, INT_MAX, 2, 0, 1},
        {INT_MAX, INT_MAX, 3, INT_MAX, INT_MAX, 1, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
