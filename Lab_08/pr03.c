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

int find_par(int a) {
    if (parent[a] == -1)
        return a;
    return (parent[a] = find_par(parent[a]));
}

void kruskal(int edges) {
    int sum = 0;
    int a, b;
    sort_by_weight(edges);
    for (int i = 0; i < edges; i++) {
        a = find_par(arr[i].src);
        b = find_par(arr[i].dest);
        if (a != b) {
            sum += arr[i].wght;
            parent[a] = b;
        }
    }
    printf("%d\n", sum);
}

int main() {
    int n, m;
    int source, destination, weight;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
        parent[i] = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &source, &destination, &weight);
        arr[i].src = source;
        arr[i].dest = destination;
        arr[i].wght = weight;
    }
    kruskal(m);
    return 0;
}
