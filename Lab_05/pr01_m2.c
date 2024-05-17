#include <stdio.h>
#define INF 99999
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"


// void printGraph(int n, int graph[n][n]) {
//     printf("Printing Graph:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d\t", graph[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// void my_prims_algorithm(int cost[], int parent[], int vertices, int graph[vertices][vertices] ) {
//     /*
//         Input:
//             cost[]: (Integer array) to store the minimum cost to reach each vertex from the starting vertex
//             parent[]: (Integer array) to store the parent of each vertex in the minimum spanning tree
//             vertices: (Integer) number of vertices in the graph
//             graph[][]: (2D Integer array)adjacency matrix representing the weighted graph
        
//         Output:
//             None - Updates graph[][] and parent[] passed as argument by the user.
        
//         Explanation:
//             For start node = 0
//             This function implements Prim's algorithm to find the minimum spanning tree of a weighted undirected graph.
//             Prim's algorithm grows a single tree (or forest) by adding vertices to the minimum spanning tree one at a time, starting from an arbitrary vertex.
//             At each step, it selects the edge with the minimum weight that connects a vertex in the minimum spanning tree to a vertex outside of it.
//             The function updates the cost array with the minimum cost to reach each vertex and the parent array with the parent of each vertex in the minimum spanning tree.
//             Finally, it prints the edges and their corresponding weights to represent the minimum spanning tree.
//     */
//     int start = 0;
//     cost[start] = 0;
//     parent[start] = -1;
//     int isVisited[vertices];
//     for( int i=0;i<vertices;i++ ) {
//         isVisited[i] = 0;
//     }

//     for( int v=0;v<vertices-1;v++ ) {
//         int minCost = INF, minIndex;
//         for( int i=0;i<vertices;i++ )  {
//             if( isVisited[i]==0 && cost[i]<minCost ) {
//                 minCost = cost[i];
//                 minIndex = i;
//             }
//         }

//         isVisited[minIndex] = 1;
//         // printf("Minimum index node(Visiting node): %d\n", minIndex+1);

//         for( int i=0;i<vertices;i++ ) {
//             if (graph[minIndex][i] && isVisited[i]==0 && graph[minIndex][i]<cost[i] ) {
//                 parent[i] = minIndex;
//                 cost[i] = graph[minIndex][i];
//                 // printf("Updating cost for node %d: %d\n", i+1, cost[i]);
//             }
//         }
//     }
// }

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

    my_prims_algorithm(cost, parent, n, graph);

    printf("Minimum Spanning Tree:\nEdge\tWeight\n");
    for( int i=1;i<n;i++ ) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
    printf("\n");
    return 0;
}
