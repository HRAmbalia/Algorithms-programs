// DFS
#include <stdio.h>

void dfs(int vertex, int n, int graph[n][n], int visited[n]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int visited[n];

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
    printf("\n");

    return 0;
}
