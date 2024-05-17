#ifndef HRA_H
#define HRA_H
#include <stdbool.h>

/**
 * @file HRA.h
 * @brief Header file containing function declarations for HRA library.
 * 
 * @version 1.0
 * @date 2024-05-18
 * @author HRAmbalia
 */

/* ------------------------ EXTRA ------------------------ */ 

// Simple summation of two integers
int addNumbers(int integer_01, int integer_02);

// Function to print 1d integer array
void my_print_1d_integer_array(int arr[], int size);

// Function to print 2d integer array
void my_print_2d_integer_array(int rows, int cols, int** arr);

// Function to print 2d matrix
void my_print_2d_matrix(int n, int graph[n][n]);

/* ------------------------ LAB 01 ------------------------ */ 

// Lab01 : Insertions Sort
void my_insertionSort_asc_for_integer_array(int integer_array[], int length_of_array);

// Lab01 : Magic Square
int** my_generate_magic_square(int length);

/* ------------------------ LAB 02 ------------------------ */ 

// Lab02 : Merge Sort using recursion
void my_merge_sort_asc_recursion(int arr[], int p, int r);

// Lab02 : Merge Sort using while
void my_merge_sort_asc_while(int arr[], int length);

// Helper function for : merge_sort_recursion
void _merge_for_recursion_while(int list[], int low, int mid, int high);

// Lab02 : Quick Sort using recursion
void my_quick_sort_asc_recursion(int arr[], int low, int high);

// Lab02 : Quick Sort using while
void my_quick_sort_asc_while(int arr[], int low, int high);

// Helper function for : temp_partition
void my_swap_two_variable(int *a, int *b);

// Helper function for : my_quick_sort
int _temporary_partition(int arr[], int low, int high);

/* ------------------------ LAB 03 ------------------------ */ 

// Lab03 : Greedy Fractional Knapsack
/**
 * @brief This function solves the fractional knapsack problem using a greedy approach. It calculates the profit-to-weight ratio for each item, sorts the items based on this ratio, and selects items one by one until the knapsack is full. If an item cannot be selected completely, it takes a fractional part of it to maximize profit.
 * 
 * @param length (int) The number of items available.
 * @param weight (float[]) An array of floats representing the weights of items.
 * @param profit (float[]) An array of floats representing the profits of items.
 * @param knapsack (int) The maximum weight the knapsack can hold.
 * @param selected_weight (float[]) An array of floats which stores weight for selected items
 * @param selected_profit (float[]) An array of floats which stores profit for selected items
 * @param selected_fraction (float[]) An array of floats which stores how much item is being selected
 * 
 * @see void _sort_with_multiple_float_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order)
 * 
 * @return (int) Returns the total profit obtained by selecting items optimally.
 */
float my_fractional_knapsack_greedy(int length, float weight[], float profit[], float knapsack, float selected_weight[], float selected_profit[], float selected_fraction[]);

// Helper function for : my_fractional_knapsack_greedy
void _sort_with_multiple_float_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order);

// Lab03 : Greedy Making change
/**
 * @brief This function uses a greedy algorithm to determine the number of each type of coin needed to make change for the given capacity. coins_array[] should be sorted in decensing order. The function updates the selected_coins and selected_counts arrays to reflect the coins used and their quantities. It returns the total value of the coins used to make change. If the total value is less than the original capacity, it means that exact change could not be generated with the given coin denominations.
 * 
 * @param length (int) The number of different coin denominations available.
 * @param coins_array[] (int[]) An array containing the values of the coin denominations.
 * @param capacity (int) The total amount of money we need to make change for.
 * @param selected_coins[] (int[]) An array to store the values of the coins used to make change.
 * @param selected_counts[] (int[]) An array to store the counts of each coin used to make change.
 * 
 * @see void my_insertion_sort_for_integer_array(int arr[], int size, int order);
 * 
 * @return (int) Returns the total value of change that was successfully generated using the available coins.
 */
int my_making_change_greedy(int length, int coins_array[], int capacity, int selected_coins[], int selected_counts[]);

// Helper function for : my_making_change_greedy
/**
 * @brief This function performs an insertion sort on the input array based on the specified order.
 * - If order is 0, the array is sorted in ascending order.
 * - If order is 1, the array is sorted in descending order.
 * The function first checks if the order parameter is valid. If it's not 0 or 1, an error message is printed and control is returned
 * The insertion sort algorithm works by iterating through the array and at each iteration,
 * placing the current element in its correct position relative to the already sorted portion of the array.
 *  The comparison logic within the while loop is adjusted based on the order parameter to achieve the desired sorting order.
 * 
 * @param arr[] (int[]) The array of integers to be sorted.
 * @param size (int) The number of elements in the array.
 * @param order (int) The order of sorting, where 0 represents ascending order and 1 represents descending order.
 * 
 * @return void - This function does not return a value. It sorts the input array in place.
 */
void my_insertion_sort_for_integer_array(int arr[], int size, int order);

/* ------------------------ LAB 04 ------------------------ */ 

// Lab04 : 0/1 Knapsack Dynamic+Recursion
/**
 * @brief This function solves the 0/1 Knapsack problem using dynamic programming and memoization. It takes the length of the items array, the weight and value arrays, the knapsack capacity, a memoization table, and an array to store selected items as inputs. The function returns the maximum value that can be obtained by selecting items to fit into the knapsack without exceeding its capacity.
 * 
 * @param length (integer) The number of items available for the knapsack problem.
 * @param weight (int[]) An array representing the weight of each item.
 * @param value (int[]) An array representing the value of each item.
 * @param capacity (int) The maximum capacity of the knapsack.
 * @param t (int**) A 2D array (matrix) for memoization of computed results.
 * @param selected_items (int[]) An array to store whether an item is selected or not.
 * 
 * @return (int) Returns the maximum value that can be obtained in the knapsack problem as well as updates selected_items[] so user can print selected items from the calling function.
 */
int my_01_knapsack_dynamic_recursion(int length, int weight[], int value[], int capacity, int **t, int *selected_items);

// Helper function for : my_01_knapsack_dynamic_recursion
/**
 * @brief This function initializes a 2D array (matrix) of size (n+1) x (m+1) and sets all elements to -1.
 * The matrix is dynamically allocated using malloc, and the function returns a pointer to the allocated memory.
 * 
 * @param n Integer representing the number of rows in the 2D array.
 * @param m Integer representing the number of columns in the 2D array.
 * 
 * @return (int**) Returns a dynamically allocated 2D array
 */
int** my_initialize_2d_dynamic_memory(int n, int m);

/* ------------------------ LAB 05 ------------------------ */ 

// Lab05 : Prim's algorithm
/**
 * @brief This function implements Prim's algorithm to find the minimum spanning tree of a weighted undirected graph
 * Prim's algorithm grows a single tree (or forest) by adding vertices to the minimum spanning tree one at a time starting from an arbitrary vertex.
 * At each step, it selects the edge with the minimum weight that connects a vertex in the minimum spanning tree to a vertex outside of it.
 * The function updates the cost array with the minimum cost to reach each vertex and the parent array with the parent of each vertex in the minimum spanning tree.
 * 
 * @param cost[] (Integer array) to store the minimum cost to reach each vertex from the starting vertex
 * @param parent[] (Integer array) to store the parent of each vertex in the minimum spanning tree
 * @param vertices (Integer) number of vertices in the graph
 * @param graph[][] (2D Integer array)adjacency matrix representing the weighted graph
 * 
 * @return None - Updates graph[][] and parent[] passed as argument by the user.
 */
void my_prims_algorithm( int cost[], int parent[], int vertices, int graph[vertices][vertices] );

// Lab05 : Find string edit distance
/**
 * @brief This function implements a dynamic programming (DP) approach to calculate the edit distance between two
 * strings. It considers three operations:
 * Insertion: Insert a character into the initial string.
 * Deletion: Delete a character from the initial string.
 * Replacement: Replace a character in the initial string.
 * The function works by recursively breaking down the problem into smaller subproblems. It uses memoization (optional) 
 * to store previously computed results and avoid redundant calculations.
 * 
 * @param init_string (character array) Pointer to the initial string.
 * @param final_string (character array) Pointer to the final string..
 * @param init_length (Integer) Length of the initial string.
 * @param final_length (Integer) Length of the final string.
 * @param memo: Pointer to a 2D integer array used for memoization (optional for efficiency).
 * 
 * @return (Integer) The minimum number of edit operations (insertions, deletions, or replacements) required to transform the initial string into the final string.
 */
int my_minimum_edit_string_distance(char *init_string, char *final_string, int init_length, int final_length, int **memo);

// Helper function for : my_minimum_edit_string_distance
/**
 * @brief Returns minimum of 3 integers passed by user
 * 
 * @param x (Integer) Integer value
 * @param y (Integer) Integer value
 * @param z (Integer) Integer value
 * 
 * @return (Integer) Returns the minimum integer
 */
int my_minimum_of_three_integer(int x, int y, int z);

/* ------------------------ LAB 06 ------------------------ */ 

// Lab06 : BFS traversal
/**
 * @brief This function implements a Breadth-First Search (BFS) algorithm to explore a connected graph. It uses a queue * to maintain the order of node exploration.
 * 
 * @param start (Integer) The starting node for the BFS traversal.
 * @param length: (Integer) The number of vertices in the graph.
 * @param graph[][] (2D integer array) representing the adjacency matrix of the graph. `graph[i][j]` indicates an edge between node `i` and node `j` (1 or 0).
 * @param parent[] (1D integer array) to store the parent node for each visited node during the BFS traversal (used for path reconstruction if needed).
 * @param traversal_order[]  A 1D integer array which stores traversal order.
 * 
 * @return None - The function updates the traversal_order[] array and parent[] array which is passed as argument, stores traversal order and parent for each node in BFS tree.
 */
void my_bfs_traversal(int start, int length, int graph[length][length], int *parent, int traversal_order[length]);

// Lab06 : DFS Traversal
/**
 * @brief This function implements a Depth-First Search (DFS) algorithm to explore a connected graph. It uses a stack to maintain the order of node exploration.
 * 
 * @param start (Integer) The starting node for the DFS traversal.
 * @param length: (Integer) The number of vertices in the graph.
 * @param graph[][] (2D integer array) representing the adjacency matrix of the graph. `graph[i][j]` indicates an edge between node `i` and node `j` (1 or 0).
 * @param parent[] (1D integer array) to store the parent node for each visited node during the DFS traversal (used to generate DFS spanning tree).
 * @param traversal_order[] (1D integer array) which stores traversal order.
 * 
 * @return None - The function updates the traversal_order[] array and parent[] array which is passed as argument, stores traversal order and parent for each node in DFS tree.
 */
void my_dfs_traversal(int start, int length, int **graph, int *parent, int *traversal_order);

/* ------------------------ LAB 07 ------------------------ */ 

// Lab07 : Topological Sort using DFS
/**
 * @brief This function performs a topological sort on a directed acyclic graph (DAG) using depth-first search (DFS).
 * It stores traversal order in the order they are visited during DFS, in topological_sort array.
 * 
 * Requirement : 
 * void _dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited, int topological_sort[length]) must be defined which performs DFS traversal to get sorted order.
 * 
 * @param length (Integer) the number of nodes in the graph
 * @param graph: (2D Integer Array) a 2D array representing the adjacency matrix of the graph. where graph[i][j] = 1 if there is an edge from node i to node j, 0 otherwise
 * @param topological_sort (1D Integer Array) An array to store the topological ordering.
 * 
 * @see void _dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited, int topological_sort[length])
 * 
 * @return None - The function updates the topological_sort[] array which is passed as argument, stores sorted order.
 */
void my_topological_sort_using_dfs(int length, int graph[length][length], int topological_sort[length]);

// Helper function for : my_topological_sort_using_dfs
void _dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited, int topological_sort[length]);

// Lab07 : Topological sort using source removal
/**
 * @brief This function performs a topological sort on a directed acyclic graph (DAG) using the source removal algorithm. It deletes nodes with indegree 0 iteratively until all nodes are visited.
 * Requirement : 
 * 
 * void _deleted_node(int length, int node, int *indegree, int graph[length][length]) must be defined which will modify the indegree array and update the graph by removing edges.
 * void my_find_indegree(int length, int graph[length][length], int *indegree) must be defined which will calculate the indegree of each node in the graph.
 * 
 * @param length (Integer) the number of nodes in the graph
 * @param indegree (1D Integer Array) an array representing the indegree of each node in the graph
 * @param graph: (2D Integer Array) a 2D array representing the adjacency matrix of the graph. where graph[i][j] = 1 if there is an edge *  from node i to node j, 0 otherwise
 * @param topological_sort (1D Integer Array) An array to store the topological ordering.
 * 
 * @see _deleted_node(int length, int node, int *indegree, int graph[length][length])
 * 
 * @return None - The function updates the topological_sort[] array which is passed as argument, stores sorted order.
 */
void my_topological_sort_using_source_removal(int length, int *indegree, int graph[length][length], int topological_sort[length]);

// Helper function for : my_topological_sort_using_source_removal
void _deleted_node(int length, int node, int *indegree, int graph[length][length]);

/**
 * @brief This function calculates the indegree of each node in the graph.
 * 
 * @param length (Integer) the number of nodes in the graph
 * @param graph: (2D Integer Array) a 2D array representing the adjacency matrix of the graph. where graph[i][j] = 1 if there is an edge *  from node i to node j, 0 otherwise
 * @param indegree (1D Integer Array) an array representing the indegree of each node in the graph
 * 
 * @return None - The function updates the indegree[] array which is passed as argument, stores indegree of each vertex.
 */
void my_find_indegree(int length, int graph[length][length], int *indegree);

// Lab07 : Find articulation point
/**
 * @brief This function identifies articulation points (AP) in a graph using Depth First Search (DFS).
 * It initializes arrays for tracking visited nodes, discovery times, lowest discovery times, and parent nodes.
 * Then, it iterates through each vertex in the graph, performing DFS if the vertex is not already visited.
 * The DFS function (_DFS_to_find_articulation_point()) is called for each unvisited vertex to identify articulation points.
 * 
 * @param length The number of nodes in the graph.
 * @param graph An adjacency matrix representing the graph passed by pointer
 * @param is_ap[] An array to mark nodes as articulation points.
 * @see _DFS_to_find_articulation_point(int length, int **graph, int node, int visited[], int disc_time[], int lowest_disc_time[], int parent[], int is_ap[])
 * @see my_minimum_of_two_integer(int a, int b)
 * 
 * @return None - The function updates the is_ap[] array to mark articulation points.
 */
void my_articulation_point(int length, int **graph, int is_ap[]);

// Helper function for : my_articulation_point
int my_minimum_of_two_integer(int a, int b);
void _DFS_to_find_articulation_point(int length, int **graph, int node, int visited[], int disc_time[], int lowest_disc_time[], int parent[], int is_ap[]);

/* ------------------------ LAB 08 ------------------------ */ 

// Lab 08 : Dijkstra's algorithm to find shortest path
/**
 * @brief This function implements Dijkstra's algorithm to find the shortest path from a given source vertex to all other vertices in the graph.
 * 
 * @param V Number of vertices in the graph.
 * @param arr[][] Adjacency matrix representing the graph.
 * @param src Source vertex.
 * @param dist[] An array to store the shortest distance from the source vertex to every other vertex.
 * 
 * @return None - shortest distance will be copied to array passed by user(ie. dist)
 */
void my_dijkstra(int V, int arr[V][V], int src, int dist[V]);

// Helper Function for : my_dijkstra
int _mindist ( int dist[], bool check[], int V );

// Lab 08 : Floyd Warshall algorithm
/**
 * @brief This function implements the Floyd Warshall algorithm to find the shortest distances between every pair of vertices in a weighted graph.
 * 
 * @param n Number of vertices in the graph.
 * @param graph[][] Adjacency matrix representing the graph.
 * 
 * @return None - Shortest distance will be updated in 2D array itself passed by user.
 */
void my_floydWarshall_algo(int n, int graph[n][n]);

#endif
