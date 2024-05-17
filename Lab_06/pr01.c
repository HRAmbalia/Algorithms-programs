// DFS

#include <stdio.h>
#include <stdlib.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void my_dfs_traversal(int start, int length, int **graph, int *parent, int *traversal_order) {
//     /*
//         Input:
//             - start: The starting node for the BFS traversal (integer).
//             - length: The number of vertices in the graph (integer).
//             - graph: A 2D integer array representing the adjacency matrix of the graph. `graph[i][j]` indicates an edge between node `i` and node `j` (1 or 0).
//             - parent: A 1D integer array to store the parent node for each visited node during the BFS traversal (used for path reconstruction if needed).
//             - traversal_order : A 1D integer array which stores traversal order.

//         Output:
//             - The function performs a Breadth-First Search (BFS) traversal on the provided graph starting from the `start` node.
//             - It prints the visited nodes and the queue contents at each step for visualization (can be removed for a cleaner output).

//         Explanation:
//             This function implements a Breadth-First Search (BFS) algorithm to explore a connected graph. It uses a queue to maintain the order of node exploration.
//     */
//     int stack[length*2];
//     int top = -1;
//     int visited[length];

//     for (int i = 0; i < length; i++) {
//         visited[i] = 0;
//     }

//     stack[++top] = start;
//     visited[start] = 1; 
//     while (top != -1) {
//         int current = stack[top--];
//         *traversal_order++ = current;

//         for (int i = length - 1; i >= 0; i--) {
//             if (graph[current][i] && !visited[i]) {
//                 stack[++top] = i;
//                 visited[i] = 1; // Mark adjacent node as visited
//                 parent[i] = current; // Update parent
//             }
//         }
//     }
// }

int main() {
    int n = 9;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        graph[i] = (int *)malloc(n * sizeof(int));

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

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = adj_matrix[i][j];

    int parent[9] = {-1};
    int start = 0;
    int traversal_order[9] = {0};

    my_dfs_traversal(start, n, graph, parent, traversal_order);

    printf("\nDFS Traversal Order :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", traversal_order[i] + 1);
    }

    printf("\n\nDFS Spanning Tree :\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("(%d, %d)\n", parent[i] + 1, i + 1);
        }
    }

    return 0;
}
