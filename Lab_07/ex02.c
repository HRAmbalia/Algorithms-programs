// Topological sort using source removal

#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"
#include <stdio.h>

// void _find_indegree(int length, int graph[length][length], int *indegree) {
//     /*
//         Input : 
//             - length: the number of nodes in the graph
//             - graph: a 2D array representing the adjacency matrix of the graph
//             - indegree: an array representing the indegree of each node in the graph
//                       (modified in this function)
//         Output : None
//         Explanation : 
//             - This function calculates the indegree of each node in the graph.
//         Requirement : None
//     */
//     for( int i=0;i<length;i++ ) {
//         for( int j=0;j<length;j++ ) {
//             if( graph[i][j]==1 ) {
//                 indegree[j]++;
//             }
//         }
//     }
// }

// void _deleted_node(int length, int node, int *indegree, int graph[length][length]) {
//     /*
//         Input : 
//             - length: the number of nodes in the graph
//             - node: the node to be deleted
//             - indegree: an array representing the indegree of each node in the graph
//                       (modified in this function)
//             - graph: a 2D array representing the adjacency matrix of the graph
//                      (modified in this function)
//         Output : 
//         Explanation : 
//             This function updates the indegree array and the graph by removing edges incident on the given node.
//         Requirement : None
//     */
//     for( int i=0;i<length;i++ ) {
//         if(graph[node][i]==1) {
//             indegree[i]--;
//         }
//     }
// }

// void my_topological_sort_using_source_removal(int length, int *indegree, int graph[length][length]) {
//     /*
//         Input : 
//             - length: the number of nodes in the graph
//             - indegree: an array representing the indegree of each node in the graph
//             - graph: a 2D array representing the adjacency matrix of the graph
//                      where graph[i][j] = 1 if there is an edge from node i to node j, 0 otherwise
//         Output : 
//         Explanation : 
//             - This function performs a topological sort on a directed acyclic graph (DAG) using the source removal algorithm.
//             - It deletes nodes with indegree 0 iteratively until all nodes are visited.
//         Requirement : 
//             - _deleted_node(int length, int node, int *indegree, int graph[length][length]) must be defined which will modify the indegree array and update the graph by removing edges.
//             - void _find_indegree(int length, int graph[length][length], int *indegree) must be defined which will calculate the indegree of each node in the graph.
//     */

//     int visited[length];
//     for( int i=0;i<length;i++ ) {
//         visited[i] = 0;
//     }

//     while(1) {
//         int temp = 0;
//         for( int i=0;i<length;i++ ) {
//             if(indegree[i]==0 && visited[i]==0){
//                 printf("deleting node : %d\n", i+1);
//                 _deleted_node(length, i, indegree, graph);
//                 visited[i] = 1;
//                 temp = 1;
//             }
//         }
//         if(temp==0) {
//             break;
//         }
//     }
// }

int main() {
    int n = 4;
    int graph[4][4] = { {0, 1, 0, 0},
                        {0, 0, 0, 1},
                        {0, 1, 0, 1},
                        {0, 0, 0, 0} };
    int indegree[4] = {0};
    _find_indegree(n, graph, indegree);
    for( int i=0;i<n;i++ ) {
        printf("in degree of %d is %d\n", i, indegree[i]);
    }
    my_topological_sort_using_source_removal(n, indegree, graph);
}
