// DFS
#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

void dfs(int vertex, int parent) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            printf("(%d,%d) ", vertex, i); // Print edge (parent, i)
            dfs(i, vertex); // Recursively visit i
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize graph and visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS Spanning Tree: ");
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(i, -1); // Start DFS from vertex i with no parent
        }
    }
    printf("\n");

    return 0;
}
