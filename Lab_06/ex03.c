// DFS
// Tree edge : is an edge that is included in the DFS tree.
// Back edge : An edge from a vertex 'u' to one of its ancestors 'v' is called as a back edge. A self-loop is considered as a back edge.
// Forward edge : An edge from a vertex 'u' to one of its descendants 'v' is called as a forward edge.
// Cross edge : An edge from a vertex 'u' to a vertex 'v' that is neither its ancestor nor its descendant is called as a cross edge.

#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int vertex, int parent, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i]) {
            if (!visited[i]) {
                printf("(%d, %d) - Tree Edge\n", vertex, i);
                dfs(i, vertex, n);
            } else if (visited[i] == 1) {
                printf("(%d, %d) - Back Edge\n", vertex, i);
            } else if (visited[i] == 2) {
                printf("(%d, %d) - Forward Edge\n", vertex, i);
            } else {
                printf("(%d, %d) - Cross Edge\n", vertex, i);
            }
        }
    }
    visited[vertex] = 2;
}

int main() {
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS Traversal :\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, n);
        }
    }

    return 0;
}
