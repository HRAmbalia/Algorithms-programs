// BFS

#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void print_1d_integer_array(int integer_array[], int n) {
//     for( int i=0;i<n;i++ ) {
//         printf("%d ", integer_array[i]);
//     }
//     printf("\n");
// }

// void my_bfs_traversal(int start, int length, int graph[length][length], int *parent) {
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

//             1. Initialization:
//                 - A queue is declared with a size sufficient to hold all possible edges (length * (length - 1)) / 2 (assuming an undirected graph).
//                 - `front` and `rear` pointers are used to manage the queue (initially `front = 0` and `rear = -1`).
//                 - A visited array (`visited`) is initialized to `0` for all nodes, indicating they haven't been visited yet.

//             2. Start Node Enqueueing:
//                 - `rear` is incremented and the starting node (`start`) is added to the queue.
//                 - The starting node is marked as visited in the `visited` array.

//             3. BFS Traversal:
//                 - A loop continues as long as there are elements in the queue (`front <= rear`).
//                     - The current node being processed is retrieved from the front of the queue (`queue[front]`), incremented by 1 for user-friendly output (starting from 1), and printed.
//                     - The visited nodes and queue contents are printed for visualization (can be replaced with your desired output).
//                     - `front` is incremented to remove the processed node from the queue.

//                 4. Explore Adjacent Nodes:
//                     - For each neighbor (`i`) of the current node:
//                         - If there's an edge (`graph[current][i] == 1`) and the neighbor hasn't been visited (`!visited[i]`), perform the following:
//                             - Add the neighbor (`i`) to the queue (`rear` is incremented and the neighbor is added).
//                             - Mark the neighbor as visited (`visited[i] = 1`).
//                             - Set the parent of the neighbor (`parent[i]`) to the current node (`current`), indicating the exploration path.
//                             - Print a message indicating the newly discovered edge.

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

//     while( front<=rear ) {

//         printf("\nVisited array: ");
//         print_1d_integer_array(visited, length);

//         printf("Queue : ");
//         for( int i=front;i<=rear;i++ ) {
//             printf("%d ", queue[i]+1);
//         }
//         printf("\n");

//         int current = queue[front++];
//         printf("Visiting node(front of the queue) : %d\n", current+1);

//         // Explore adjacent nodes of current
//         for( int i=0;i<length;i++ ) {
//             if( graph[current][i] && !visited[i] ) {
//                 rear++;
//                 queue[rear] = i; // Add adjacent nodes to the queue
//                 visited[i] = 1; // Node is now visited
//                 parent[i] = current;// As we reached from curent to this node
//                 printf("Adding edge: (%d, %d)\n", current+1, i+1);
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

    printf("BFS Spanning Tree Edges:\n");
    my_bfs_traversal(start, n, graph, parent);

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
