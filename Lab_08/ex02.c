// All Pairs Shortest path - Floyd - Warshal Algorithm

#include <stdio.h>

#define MAX_VERTICES 100

void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Graph Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        printf("Iteration k = %d\n", k);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    printf("        Found a shorter path from vertex %d to %d through vertex %d\n", i, j, k);
                    printf("        Old distance: %d, New distance: %d\n", graph[i][j], graph[i][k] + graph[k][j]);
                    graph[i][j] = graph[i][k] + graph[k][j];
                    printGraph(graph, n);
                } else {
                    printf("        No shorter path found from vertex %d to %d through vertex %d\n", i, j, k);
                }
            }
        }
    }
}

int main(void) {
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);
    
    printf("Shortest path matrix is:\n");
    printGraph(graph, n);
    return 0;
}
