// All Pairs Shortest path - Floyd - Warshal Algorithm

#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void my_floydWarshall_algo(int n, int graph[n][n]) {
//     /*
//         Input :
//             - n: Number of vertices in the graph.
//             - graph[][]: Adjacency matrix representing the graph.
//         Output : None, Output will be updated in passed 2D array itself.
//         Explanation : 
//             This function implements the Floyd Warshall algorithm to find the shortest distances between every pair of vertices in a weighted graph.
//     */

//     for ( int k=0;k<n;k++ ) {
//         for ( int i=0;i<n;i++ ) {
//             for ( int j=0;j<n;j++ ) {
//                 if (graph[i][j] > graph[i][k]+graph[k][j] ) {
//                     graph[i][j] = graph[i][k]+graph[k][j];
//                 }
//             }
//         }
//     }
// }

int main() {
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int graph[n][n];

    printf("Enter the adjacency matrix :\n");
    for ( int i=0;i<n;i++ )
        for ( int j=0;j<n;j++ )
            scanf("%d", &graph[i][j]);

    my_floydWarshall_algo(n, graph);

    printf("Shortest path matrix is : \n");
    for ( int i=0;i<n;i++ ) {
        for ( int j=0;j<n;j++ )
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    return 0;
}

// 0 10 20 500 500 50
// 20 0 500 30 10 100
// 20 500 0 10 30 500
// 50 20 10 0 10 20
// 500 10 33 20 0 1
// 500 1000 2 2 1 0
