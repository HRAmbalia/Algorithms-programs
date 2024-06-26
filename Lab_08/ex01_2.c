// Dijkstra algorithm

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 6

int mindist(int dist[], bool check[]) {
    int min = INT_MAX, minindex;
    for (int i = 0; i < V; i++)
        if (check[i] == false && dist[i] <= min) {
            min = dist[i]; // update when min is greater than dist recorded
            minindex = i;
        }
    return minindex;
}

void dijkstra(int arr[V][V], int src, int trace) {
    int dist[V]; // shortest distance from src to i.
    bool check[V]; // check[i] will true if vertex i is included in shortest path
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        check[i] = false;
    }
    dist[src] = 0; // cause starting node
    for (int i = 0; i < V - 1; i++) {
        int min = mindist(dist, check); // pick the minimum distance vertex.
        check[min] = true; // mark the picked vertex as processed
        if (trace == 1)
            printf("Picked vertex: %d\n", min);
        for (int j = 0; j < V; j++) {
            if (trace == 1) {
                printf("Check condition for vertex %d:\n", j);
                printf("  check[%d] = %s\n", j, check[j] ? "true" : "false");
                printf("  arr[%d][%d] = %d\n", min, j, arr[min][j]);
                printf("  dist[%d] != INT_MAX: %s\n", min, dist[min] != INT_MAX ? "true" : "false");
                printf("  dist[%d] + arr[%d][%d] < dist[%d]: %s\n", min, min, j, j, dist[min] + arr[min][j] < dist[j] ? "true" : "false");
            }
            if (!check[j] && arr[min][j] && dist[min] != INT_MAX && dist[min] + arr[min][j] < dist[j]) {
                dist[j] = dist[min] + arr[min][j]; // update dist[v] by shortest distance
                if (trace == 1)
                    printf("Updated distance to vertex %d: %d\n", j, dist[j]);
            }
            else if (trace == 1) {
                printf("Not updating distance to vertex %d\n", j);
            }
        }
    }
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]); // prints answer
}

int main() {
    int graph[V][V] = {{0, 10, 20, 0, 0, 0},
                       {20, 0, 0, 30, 10, 0},
                       {20, 0, 0, 10, 30, 0},
                       {0, 20, 10, 0, 10, 20},
                       {0, 10, 33, 20, 0, 1},
                       {0, 0, 0, 2, 1, 0}};
    int src = 0;
    int trace = 1; // Set trace to 1 to enable detailed tracing
    // for ( int i=0;i<V;i++ )
    //  for ( int j=0;j<V;j++ )
    //      scanf("%d", &graph[i][j]);
    // scanf("%d", &src);
    dijkstra(graph, src, trace);
    return 0;
}
