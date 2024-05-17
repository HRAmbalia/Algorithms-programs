// Topological sort using DFS

#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"
#include <stdio.h>

// void _dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited, int topological_sort[length]) {
//     /*
//         Input: 
//             - start: The starting node for DFS traversal.
//             - length: The number of nodes in the graph.
//             - graph: A 2D array representing the graph's adjacency matrix.
//             - global_visited: An array indicating nodes visited across different invocations.
//             - topological_sort: An array to store the topological ordering.
//         Output: None (Output is printed directly)
//         Explanation: Performs Depth-First Search (DFS) traversal on a graph represented by an adjacency matrix and performs topological sorting.
//         Requirement : This function is required for another function, `my_topological_sort_using_dfs`,
//             which depends on this function being defined.
//     */
//     int visited[length];
//     for( int i=0;i<length;i++ ) {
//         visited[i] = global_visited[i];
//     }
//     int stack[(length*(length-1))/2];
//     int top = -1;
//     top++;
//     stack[top] = start;
//     visited[start] = 1;
//     while( top!=-1 ) {
//         int current = stack[top];
//         // printf("Visiting node : %d\n", current+1);
//         top--;
//         for( int i=0;i<length;i++ ) {
//             if (graph[current][i] && !visited[i]) {
//                 top++;
//                 stack[top] = i; // Add adjecent nodes to stack
//                 visited[i] = 1; // Node is now visited
//                 // printf("Adding node %d to stack\n", i+1);
//             }
//         }
//         topological_sort[current] = current + 1; // Add current node to topological sort array
//     }
//     for( int i=0;i<length;i++ ) {
//         global_visited[i] = visited[i];
//     }
// }

// void my_topological_sort_using_dfs(int length, int graph[length][length], int topological_sort[length]) {
//     /*
//         Input: 
//             - length: the number of nodes in the graph
//             - graph: a 2D array representing the adjacency matrix of the graph
//                      where graph[i][j] = 1 if there is an edge from node i to node j, 0 otherwise
//         Output: 
//         Explanation: 
//             - This function performs a topological sort on a directed acyclic graph (DAG) using depth-first search (DFS).
//             - It prints the nodes in the order they are visited during DFS, which represents a topological ordering.
//         Requirement : 
//             - The graph must be represented using an adjacency matrix.
//             - Another function '_dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited)' is required as helper function for this program
//     */
//     int global_visited[length];
//     for( int i=0;i<length;i++ )
//         global_visited[i] = 0;
//     for( int i=0;i<length;i++ ) {
//         if( global_visited[i]==0 ) {
//             // printf("\nStarting DFS from node %d\n", i+1);
//             _dfs_for_topological_sort(i, length, graph, global_visited, topological_sort);
//         }
//     }
// }

int main() {
    int n = 4;
    int graph[4][4] = { {0, 1, 0, 0},
                        {0, 0, 0, 1},
                        {0, 1, 0, 1},
                        {0, 0, 0, 0} };
    int topological_sort[4] = {0};
    int global_visited[4] = {0};
    int visited[4] = {0};
    my_topological_sort_using_dfs(n, graph, topological_sort);
    
    printf("Topological Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d -", topological_sort[i]);
    }
    printf("\n");
}
