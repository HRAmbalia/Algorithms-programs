// dijkstra algorithm

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// 
// int _mindist ( int dist[], bool check[], int V ) {
//     /*
//         Input : 
//             - dist[]: An array storing the shortest distance of vertices from the source vertex.
//             - check[]: An array representing whether a vertex is included in the shortest path tree or not.
//             - V: Number of vertices in the graph.
//         Output : 
//             - Returns the index of the vertex with the minimum distance value, which is not yet included in the shortest path tree.
//         Explanation : 
//             This function iterates through all the vertices not yet included in the shortest path tree and returns the index of the vertex with the minimum distance value. 
//     */

//     int min = INT_MAX, minindex;
//     for ( int i=0;i<V;i++ )
//         if ( check[i]==false && dist[i]<=min ) {
//             min = dist[i]; // update when min is greater than dist recorded
//             minindex = i;
//         }
//     return minindex;
// }


// void my_dijkstra(int V, int arr[V][V], int src, int dist[V]) {
//     /*
//         Input : 
//             - V: Number of vertices in the graph.
//             - arr[][]: Adjacency matrix representing the graph.
//             - src: Source vertex.
//             - dist[]: An array to store the shortest distance from the source vertex to every other vertex.
//         Output : None, output will be copied to array passed by user as last argument. 
//         Explanation : 
//             This function implements Dijkstra's algorithm to find the shortest path from a given source vertex to all other vertices in the graph.
//         Requirement : 
//             Function : int _mindist ( int dist[], bool check[], int V ) -> Which returns the index of the minimum valued node 
//     */

//     bool check[V]; // check[i] will true if vertex i is included in shortest path
//     for ( int i=0;i<V;i++ ) {
//         check[i] = false;
//     }
//     dist[src] = 0; // cause starting node
//     for ( int i=0;i<V-1;i++ ) {
//         int min = _mindist(dist, check, V); // pick the minimum distance vertex.
//         check[min] = true; // mark the picked vertex as processed
//         for ( int j=0;j<V;j++ )
//             if ( !check[j] && arr[min][j] && dist[min]!=INT_MAX && dist[min]+arr[min][j]<dist[j] )
//                 dist[j] = dist[min]+arr[min][j]; // update dist[v] by shortest distance
//     }
// }


int main() {
    int V = 6;
    int graph[6][6]={ 
            {0, 10, 20, 0, 0, 0},
            {20, 0, 0, 30, 10, 0},
            {20, 0, 0, 10, 30, 0},
            {0, 20, 10, 0, 10, 20},
            {0, 10, 33, 20, 0, 1},
            {0, 0, 0, 2, 1, 0} 
        };
    int src = 0;
    int dist[V];
    for ( int i=0;i<V;i++ ) {
        dist[i] = INT_MAX; // shortest distance from src to i.
    }
    
    // for ( int i=0;i<V;i++ )
    //  for ( int j=0;j<V;j++ )
    //      scanf("%d", &graph[i][j]);
    // scanf("%d", &src);
    my_dijkstra( V, graph, src, dist );

    printf("Node\tMinimum Distance\n");
    for ( int i=0;i<V;i++ )
        printf("%d\t%d\n", i, dist[i]);
    return 0;
}
