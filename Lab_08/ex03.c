// Kruskal's algorithm

#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src;
    int dest;
    int wght;
};
struct Edge arr[3000];
int parent[100000];

void sort_by_weight(int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].wght > arr[j + 1].wght) {
                struct Edge temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void kruskal(int edges) {
    int sum = 0;
    int a, b;
    for (int i = 0; i < edges; i++) {
        printf("Available choices after iteration %d:\n", i + 1);
        for (int j = i; j < edges; j++) {
            printf("  Edge from vertex %d to vertex %d with weight %d\n", arr[j].src, arr[j].dest, arr[j].wght);
        }
        sort_by_weight(edges);
        printf(" Considering edge from vertex %d to vertex %d with weight %d\n", arr[i].src, arr[i].dest, arr[i].wght);
    }
    printf("Total weight of the minimum spanning tree: %d\n", sum);
}

int main() {
    int n, m;
    int source, destination, weight;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
        parent[i] = -1;
    printf("Enter the edges in the format: source destination weight\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &source, &destination, &weight);
        arr[i].src = source;
        arr[i].dest = destination;
        arr[i].wght = weight;
    }
    kruskal(m);
    return 0;
}


// 0 1 4
// 0 2 3
// 1 2 1
// 1 3 2
// 2 3 4
// 3 4 2
// 2 4 4