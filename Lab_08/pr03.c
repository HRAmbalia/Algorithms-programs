// my_kruskal_algo's algorithm

#include <stdio.h>
#include <stdlib.h>

struct _krushkal_struct_Edge {
    int src;
    int dest;
    int wght;
};

void _sort_by_weight(int size, struct _krushkal_struct_Edge array[]) {
    for ( int i=0;i<size-1;i++ ) {
        for ( int j=0;j<size-i-1;j++ ) {
            if (array[j].wght > array[j+1].wght) {
                struct _krushkal_struct_Edge temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int _find_parent(int a, int parent[]) {
    if (parent[a] == -1)
        return a;
    return (parent[a] = _find_parent(parent[a], parent));
}

void my_kruskal_algo(int edges, struct _krushkal_struct_Edge array[], int parent[]) {
    int sum = 0;
    int a, b;
    _sort_by_weight(edges, array);
    for (int i = 0; i < edges; i++) {
        a = _find_parent(array[i].src, parent);
        b = _find_parent(array[i].dest, parent);
        if (a != b) {
            sum += array[i].wght;
            parent[a] = b;
        }
    }
    printf("%d\n", sum);
}

int main() {
    int n, m;
    int source, destination, weight;
    struct _krushkal_struct_Edge array[3000];
    int parent[100000];
    scanf("%d", &n);
    scanf("%d", &m);
    for ( int i=0;i<n;i++ )
        parent[i] = -1;
    for ( int i=0;i<m;i++ ) {
        scanf("%d %d %d", &source, &destination, &weight);
        array[i].src = source;
        array[i].dest = destination;
        array[i].wght = weight;
    }
    my_kruskal_algo(m, array, parent);
    return 0;
}
