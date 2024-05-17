#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// int my_minimum_of_two_integer(int a, int b) {
//     return (a<b) ? a:b;
// }

// void _DFS_to_find_articulation_point(int length, int **graph, int node, int visited[], int disc_time[], int lowest_disc_time[], int parent[], int is_ap[]) {
//     /*
//         Input:
//             - length: The number of nodes in the graph.
//             - graph: An adjacency matrix representing the graph.
//             - node: The current node being visited during DFS traversal.
//             - visited[]: An array to keep track of visited nodes.
//             - disc_time[]: An array to store the discovery time of each node.
//             - lowest_disc_time[]: An array to store the lowest discovery time reachable from each node.
//             - parent[]: An array to store the parent of each node in the DFS traversal tree.
//             - is_ap[]: An array to mark nodes as articulation points.
            
//         Output:
//             No explicit output. The function updates various arrays (disc_time[], lowest_disc_time[], parent[], is_ap[]) to store information about the graph and articulation points.
        
//         Explanation:
//             - This function implements Depth First Search (DFS) to traverse a graph and identify articulation points (AP).
//             - It starts by initializing some variables and marking the current node as visited.
//             - Then, it updates the discovery time and lowest discovery time of the current node.
//             - The function iterates over all adjacent nodes of the current node.
//                 - If an adjacent node is not visited, it recursively calls DFS on that node, marking the current node as its parent.
//                 - It updates the lowest discovery time of the current node based on the child's lowest discovery time.
//                 - If the current node is the root of the DFS tree and has more than one child, it's marked as an articulation point.
//                 - If the current node is not the root and the lowest discovery time of the child is greater than or equal to the discovery time of the current node, it's marked as an articulation point.
//                 - If the adjacent node is already visited and not the parent of the current node, it updates the lowest discovery time of the current node based on the adjacent node's discovery time.
//             - The function does not return any explicit value but updates various arrays to reflect the DFS traversal and identify articulation points.
//     */

//     static int time = 0;
//     int children = 0;
//     visited[node] = 1;
//     disc_time[node] = lowest_disc_time[node] = ++time;
    
//     // printf("\nVisiting node %d\n", node);
//     // printf("Updated disc_time[%d] = %d\n", node, disc_time[node]);
//     // printf("Updated lowest_disc_time[%d] = %d\n", node, lowest_disc_time[node]);

//     for( int v=0;v<length;v++ ) {
//         if( graph[node][v] ) {
//             if ( !visited[v] ) {
//                 children++;
//                 parent[v] = node;
//                 // printf("DFS from %d to %d\n", node, v);
//                 _DFS_to_find_articulation_point(length, graph, v, visited, disc_time, lowest_disc_time, parent, is_ap);
//                 // printf("Returned from DFS from %d to %d\n", node, v);
//                 lowest_disc_time[node] = my_minimum_of_two_integer(lowest_disc_time[node], lowest_disc_time[v]);
//                 // printf("Updated lowest_disc_time[%d] = %d\n", node, lowest_disc_time[node]);
//                 if( parent[node]==-1 && children>1 ) {
//                     is_ap[node] = 1;
//                     // printf("Articulation point found: %d\n", node);
//                 }
//                 if( parent[node]!=-1 && lowest_disc_time[v]>=disc_time[node] ) {
//                     is_ap[node] = 1;
//                     // printf("Articulation point found: %d\n", node);
//                 }
//             }
//             else if( v!=parent[node] ) {
//                 lowest_disc_time[node] = my_minimum_of_two_integer(lowest_disc_time[node], disc_time[v]);
//                 // printf("Back edge found between %d and %d\n", node, v);
//                 // printf("Updated lowest_disc_time[%d] = %d\n", node, lowest_disc_time[node]);
//             }
//         }
//     }
// }

// void my_articulation_point(int length, int **graph, int is_ap[]) {
//     /*
//         Input :
//             - length: The number of nodes in the graph.
//             - graph: An adjacency matrix representing the graph.
//             - is_ap[]: An array to mark nodes as articulation points.
//         Output :
//             No explicit output. The function updates the is_ap[] array to mark articulation points.
//         Explanation : 
//             This function identifies articulation points (AP) in a graph using Depth First Search (DFS).
//             It initializes arrays for tracking visited nodes, discovery times, lowest discovery times, and parent nodes.
//             Then, it iterates through each vertex in the graph, performing DFS if the vertex is not already visited.
//             The DFS function (_DFS_to_find_articulation_point) is called for each unvisited vertex to identify articulation points.
//         Requirement : 
//             - function _DFS_to_find_articulation_point(length, graph, i, visited, disc_time, lowest_disc_time, parent, is_ap) which is used to perform DFS to find articulation points.
//     */
//     int visited[length];
//     int disc_time[length];
//     int lowest_disc_time[length];
//     int parent[length];
    
//     for( int i=0;i<length;i++ ) {
//         parent[i] = -1;
//         visited[i] = false;
//         is_ap[i] = false;
//     }
    
//     for( int i=0;i<length;i++ )
//         if (!visited[i])
//             _DFS_to_find_articulation_point(length, graph, i, visited, disc_time, lowest_disc_time, parent, is_ap);
// }

int main() {
    int V = 9;
    
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    // Populate the adjacency matrix
    int adj_matrix[9][9] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = adj_matrix[i][j];

    int is_ap[V];

    my_articulation_point(V, graph, is_ap);

    printf("Articulation Points: ");
    for( int i=0;i<V;i++ )
        if( is_ap[i] )
            printf("%d - ", i+1);
    printf("\n");
    
    return 0;
}
