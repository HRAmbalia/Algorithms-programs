// DFS

#include <stdio.h>
#include <stdlib.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void print_1d_integer_array(int *integer_array, int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ", integer_array[i]);
//     printf("\n");
// }

// void my_dfs_traversal(int start, int length, int **graph, int *parent) {
//     /*
//         Input: 
//             - start: The starting node for DFS traversal.
//             - length: The number of nodes in the graph.
//             - graph: A 2D array representing the graph's adjacency matrix.
//             - parent: An array to store the parent node for each node visited during traversal.
//         Output: None (Output is printed directly)
//         Explanation: Performs Depth-First Search (DFS) traversal on a graph represented by an adjacency matrix.
//     */
//     int stack[(length * (length - 1)) / 2];
//     int top = -1;
//     int visited[9];
//     for (int i = 0; i < length; i++)
//         visited[i] = 0;

//     top++;
//     stack[top] = start;
//     visited[start] = 1;

//     printf("DFS Traversal order :\n");

//     while (top >= 0) {

//         printf("\nVisited array: ");
//         print_1d_integer_array(visited, length);

//         printf("Stack : ");
//         for (int i = 0; i <= top; i++)
//         {
//             printf("%d ", stack[i] + 1);
//         }
//         printf("\n");

//         int found = 0;
//         // Visiting each node : O(n)
//         int current = stack[top];
//         printf("Visiting node(top of the stack) : %d\n", current + 1);
//         top--; // This is not correct, we shouldn't have to pop at this point

//         // Exploring adjacent nodes of current
//         for (int i = 0; i < length; i++)
//         {
//             // Visiting adjucent nodes for each vertices : O()
//             if (graph[current][i] && !visited[i])
//             {
//                 top++;
//                 stack[top] = i;      // Add adjecent nodes to stack
//                 visited[i] = 1;      // Node is now visited
//                 parent[i] = current; // As we reached from curent to this node
//                 found = 1;
//                 printf("Adding edge: (%d, %d)\n", current + 1, i + 1);
//                 break;
//             }
//         }
//         if (!found)
//             top--;
//     }

//     printf("\nDFS Spanning Tree :\n");
//     for (int i = 0; i < length; i++)
//         if (parent[i] != -1)
//             printf("(%d, %d)\n", parent[i] + 1, i + 1);
// }

int main()
{
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

    my_dfs_traversal(start, n, graph, parent);

    return 0;
}

/*
    Time complexity :
    Visiting n vertex once : O(n)
    For each vertex, exploring its m adjacent nodes(edges) : O(n+m)
*/
