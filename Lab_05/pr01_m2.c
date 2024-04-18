#include <stdio.h>
#define INF 99999

void printGraph(int n, int graph[n][n]) {
    printf("Printing Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void my_prims_algorithm(int cost[], int parent[], int vertices, int graph[vertices][vertices] ) {
    printf("Running Prim's Algorithm...\n");
    int start = 0;
    cost[start] = 0;
    parent[start] = -1;
    int isVisited[vertices];
    for( int i=0;i<vertices;i++ ) {
        isVisited[i] = 0;
    }

    for( int v=0;v<vertices-1;v++ ) {
        int minCost = INF, minIndex;
        for( int i=0;i<vertices;i++ )  {
            if( isVisited[i]==0 && cost[i]<minCost ) {
                minCost = cost[i];
                minIndex = i;
            }
        }

        isVisited[minIndex] = 1;
        printf("Minimum index node(Visiting node): %d\n", minIndex+1);

        for( int i=0;i<vertices;i++ ) {
            if (graph[minIndex][i] && isVisited[i]==0 && graph[minIndex][i]<cost[i] ) {
                parent[i] = minIndex;
                cost[i] = graph[minIndex][i];
                printf("Updating cost for node %d: %d\n", i+1, cost[i]);
            }
        }
    }

    printf("Minimum Spanning Tree:\nEdge\tWeight\n");
    for( int i=1;i<vertices;i++ ) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    int parent[n];
    int cost[n];
    int isVisited[n];

    for( int i=0;i<n;i++ ) {
        cost[i] = INF;
    }

    printGraph(n, graph);
    my_prims_algorithm(cost, parent, n, graph);

    return 0;
}
