// BFS

#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void print_1d_integer_array(int integer_array[], int n) {
//     for( int i=0;i<n;i++ ) {
//         printf("%d ", integer_array[i]);
//     }
//     printf("\n");
// }

// void my_bfs_traversal(int start, int length, int graph[length][length], int *parent, int traversal_order[length]) {
//     /*
//         Input:
//             - start: The starting node for the BFS traversal (integer).
//             - length: The number of vertices in the graph (integer).
//             - graph: A 2D integer array representing the adjacency matrix of the graph. `graph[i][j]` indicates an edge between node `i` and node `j` (1 or 0).
//             - parent: A 1D integer array to store the parent node for each visited node during the BFS traversal (used for path reconstruction if needed).

//         Output:
//             - The function performs a Breadth-First Search (BFS) traversal on the provided graph starting from the `start` node.
//             - It prints the visited nodes and the queue contents at each step for visualization (can be removed for a cleaner output).

//         Explanation:
//             This function implements a Breadth-First Search (BFS) algorithm to explore a connected graph. It uses a queue to maintain the order of node exploration.

//     This function provides a step-by-step BFS traversal of the graph, allowing you to visualize the exploration process. The `parent` array can be used to reconstruct the path from the starting node to any reached node if needed. 
//     */

//     int queue[(length*(length-1))/2];
//     int front = 0;
//     int rear = -1;
//     int visited[9];
//     for( int i=0;i<length;i++ ) 
//         visited[i] = 0; 

//     rear++;
//     queue[rear] = start;
//     visited[start] = 1;
//     int orderIndex = 0;

//     while( front<=rear ) {

//         // printf("\nVisited array: ");
//         // print_1d_integer_array(visited, length);

//         // printf("Queue : ");
//         // for( int i=front;i<=rear;i++ ) {
//         //     printf("%d ", queue[i]+1);
//         // }
//         // printf("\n");

//         int current = queue[front++];
//         traversal_order[orderIndex++] = current+1;
//         // printf("Visiting node(front of the queue) : %d\n", current+1);

//         // Explore adjacent nodes of current
//         for( int i=0;i<length;i++ ) {
//             if( graph[current][i] && !visited[i] ) {
//                 rear++;
//                 queue[rear] = i; // Add adjacent nodes to the queue
//                 visited[i] = 1; // Node is now visited
//                 parent[i] = current;// As we reached from curent to this node
//                 // printf("Adding edge: (%d, %d)\n", current+1, i+1);
//             }
//         }
//     }
// }

int main() {
    int n = 9;

    int graph[9][9] = {
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
    int parent[9] = {-1};
    int start = 0;
    int traversal_order[9] = {0};

    my_bfs_traversal(start, n, graph, parent, traversal_order);

    printf("BFS Traversal Order : ");
    for( int i=0;i<n;i++ ) {
        printf("%d ", traversal_order[i]);
    }

    printf("\nBFS Spanning Tree :\n");
    for( int i=0;i<n;i++ ) {
        if( parent[i]!=-1 ) {
            printf("(%d, %d)\n", parent[i]+1, i+1);
        }
    }
    
    

    return 0;
}

/*
    Time complexity : 
    Visiting n vertex once : O(n)
    For each vertex, exploring its m adjacent nodes(edges) : O(n+m)
*/
