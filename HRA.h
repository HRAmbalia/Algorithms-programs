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
/**
 * @brief This function sums two integer passed as argument
 * 
 * @param integer_01 (int) first number 
 * @param integer_02 (int) second number 
 * 
 * @return (int) Returns sum of two integer passed
 */
int addNumbers(int integer_01, int integer_02);

// Function to print 1d integer array
/**
 * @brief This function 1D integer array
 * 
 * @param arr[] (int[]) Integer array
 * @param size (int) size of the array passed
 * 
 * @return None - Prints array passed by user
 */
void my_print_1d_integer_array(int arr[], int size);

// Function to print 2d integer array
/**
 * @brief This function prints 2D integer array which is dynamically allocated
 * 
 * @param rows (int) No of rows of 2D array
 * @param cols (int) No of columns of 2D array
 * @param arr (int**) pointer to the dymanically allocated 2D matrix
 * 
 * @return None - Prints 2D array passed by user
 */
void my_print_2d_integer_array(int rows, int cols, int** arr);

// Function to print 2d matrix
/**
 * @brief This function prints 2D integer array which is dynamically allocated
 * 
 * @param n (int) No of rows and columns in passed 2D array
 * @param graph[][] (int[][]) passed 2D graph
 *  
 * @return None - Prints 2D array passed by user
 */
void my_print_2d_matrix(int n, int graph[n][n]);

// Find max of two integer
/**
 * @brief This function returns maximum of two integer
 * 
 * @param a (int) first integer
 * @param b (int) second integer
 * 
 * @return (int) - return max of two integer
 */
int my_maximum_of_two_integer(int a, int b);

/* ------------------------ LAB 01 ------------------------ */ 

// Lab01 : Insertions Sort
/**
 * @brief This function performs the insertion sort algorithm on the given integer array in ascending order. It takes the input array and its length as parameters and modifies the array in-place to achieve the sorted order.
 * 
 * @param integer_array (int[]) An array of integers to be sorted.
 * @param length_of_array (int) The length of the integer_array.
 * 
 * @return None - The array integer_array[] sorted in non-decreasing order.
 */
void my_insertionSort_asc_for_integer_array(int integer_array[], int length_of_array);

// Lab01 : Magic Square
/**
 * @brief This function generates a magic square of order 'length' using the Siamese method.  It takes the size of the magic square as input and returns a dynamically allocated 2D array representing the generated magic square.
 * 
 * @param length (int) The size of the magic square (number of rows or columns as it'll be square matrix).
 * 
 * @return (int**) Returns a dynamically allocated 2D array representing the magic square.
 */
int** my_generate_magic_square(int length);

/* ------------------------ LAB 02 ------------------------ */ 

// Lab02 : Merge Sort using recursion
/**
 * @brief This function implements the recursive part of the merge sort algorithm. It recursively divides the input array into two halves until each subarray has only one element. Then it merges the sorted subarrays using the merge_for_recursion_while function.
 * 
 * @param arr[] (int[]) An array of integers to be sorted.
 * @param p (int) The starting index of the subarray to be sorted.
 * @param r (int) The ending index of the subarray to be sorted.
 * 
 * @see void _merge_for_recursion_while(int list[], int low, int mid, int high)
 * 
 * @return None - The array arr[] sorted in non-decreasing order.
 */
void my_merge_sort_asc_recursion(int arr[], int p, int r);

// Lab02 : Merge Sort using while
/**
 * @brief This function implements the iterative version of the merge sort algorithm using a while loop. It divides the array into subarrays of increasing size and merges them in sorted order using the _merge_for_recursion_while function.
 * 
 * @param arr[] (int[]) An array of integers to be sorted.
 * @param length (int) The number of elements in the array.
 * 
 * @see void _merge_for_recursion_while(int list[], int low, int mid, int high)
 * 
 * @return None - The array arr[] sorted in non-decreasing order.
 */
void my_merge_sort_asc_while(int arr[], int length);

// Helper function for : merge_sort_recursion
void _merge_for_recursion_while(int list[], int low, int mid, int high);

// Lab02 : Quick Sort using recursion
/**
 * @brief This function implements the recursive part of the quick sort algorithm. It selects a pivot element from the array and partitions the array such that elements smaller than the pivot are placed before it, and elements greater than the pivot are placed after it. Then, it recursively sorts the subarrays before and after the pivot.
 * 
 * @param arr[] (int[]) An array of integers to be sorted.
 * @param length (int) The number of elements in the array.
 * 
 * @see int _temporary_partition(int arr[], int low, int high)
 * 
 * @return None - The array arr[] sorted in non-decreasing order.
 */
void my_quick_sort_asc_recursion(int arr[], int low, int high);

// Lab02 : Quick Sort using while
/**
 * @brief This function will sort the integer_array[] using recursion.
 * 
 * @param arr[] (int[]) An array of integers to be sorted.
 * @param low (int) The starting index of the subarray to be sorted.
 * @param high (int) The ending index of the subarray to be sorted.
 * 
 * @see int _temporary_partition(int arr[], int low, int high)
 * 
 * @return None - The array arr[] sorted in non-decreasing order.
 */
void my_quick_sort_asc_while(int arr[], int low, int high);

// Helper function for : temp_partition
/**
 * @brief This function will swap two integer variable passed by reference
 * 
 * @param a (*a) first integer passed by address
 * @param b (*b) second integer passed by address
 * 
 * @return None - Two variables will be swapped
 */
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
/**
 * @brief This function returns minimum of two integer
 * 
 * @param a (int) first integer
 * @param b (int) second integer
 * 
 * @return (int) - return min of two integer
 */
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

/* ------------------------ LAB 09 ------------------------ */ 

// Lab 09 : String matching naive method
/**
 * @brief This function implements a naive string matching algorithm. It iterates through each position in the array and checks if the substring starting from that position matches the pattern. If a match is found, it returns the starting index. If no match is found after checking all positions, it returns -1.
 * 
 * @param array[] (Character array) in which we want to find the pattern.
 * @param pattern[] (Character array) that we want to search for in the array.
 * 
 * @return (int) Returns the starting index of the first occurrence of the pattern in the array. Returns -1 if the pattern is not found in the array.
 */
int my_naive_string_match(char array[], char pattern[]);

// Lab 09 : String matching recursive method
/**
 * @brief This function implements a recursive string matching algorithm. It checks if the substring can be found starting at the given index in the main string. If the length of the remaining portion of mainStr is less than the length of substr, it returns -1 (base case). If the substring matches the portion of mainStr starting at the current index, it returns the current index. If not, it recursively calls itself with the next index, continuing the search.
 * 
 * @param mainStr (char *) A pointer to the main string in which we want to find the substring.
 * @param substr (char *) A pointer to the substring we are searching for within mainStr.
 * @param index (int) The current index in mainStr from which we are checking for the substring.
 * 
 * @return (int) Returns the starting index of the first occurrence of the substring within the main string. Returns -1 if the substring is not found.
 */
int my_recursive_string_match(char *mainStr, char *substr, int index);

/* ------------------------ LAB 10 ------------------------ */ 

/* ------------------------ LAB 11 ------------------------ */ 

struct _point {
    int x, y;
};

// Lab 11 : Check collinearity
/**
 * @brief The function calculates the slopes between the pairs of points (p1, p2) and (p2, p3). It uses the fact that for three points to be collinear, the slope of the line between p1 and p2 should be the same as the slope of the line between p2 and p3. The slopes are calculated using the formula (y2 - y1) / (x2 - x1).
 * 
 * @param p1 (struct _point) a structure representing the first point with coordinates (x1, y1)
 * @param p2 (struct _point) a structure representing the second point with coordinates (x2, y2)
 * @param p3 (struct _point) a structure representing the third point with coordinates (x3, y3)
 * 
 * @return (int) Returns 1 if the points are collinear. Returns 0 if the points are not collinear.
 */
int my_check_if_3_point_Collinear(struct _point p1, struct _point p2, struct _point p3);

// Lab 11 : Check direction
/**
 * @brief The function calculates the direction of the point p1 with respect to the line segment p0-p2 using the cross product.
 * 
 * @param p1 (struct _point) a structure representing the first point with coordinates (x1, y1)
 * @param p2 (struct _point) a structure representing the second point with coordinates (x2, y2)
 * @param p3 (struct _point) a structure representing the third point with coordinates (x3, y3)
 * 
 * @return (int) Returns a positive value if p1 is to the left of the line segment p0-p2. Returns a negative value if p1 is to the right of the line segment p0-p2. Returns 0 if p1 is on the line segment p0-p2
 */
int my_direction_of_p1_wrt_p2(struct _point p0, struct _point p1, struct _point p2);

// Lab 11 : Check Intersection
/**
 * @brief The function checks the orientations of the points to determine if the two line segments intersect.
 * 
 * @param p1 (struct _point) a structure representing the first _point of the first line segment with coordinates (x1, y1)
 * @param q1 (struct _point) a structure representing the second _point of the first line segment with coordinates (x2, y2)
 * @param p2 (struct _point) a structure representing the first _point of the second line segment with coordinates (x3, y3)
 * @param q2 (struct _point) a structure representing the second _point of the second line segment with coordinates (x4, y4)
 * 
 * @see int _orientation_for_intersection(struct _point p,struct _point q, struct _point r)
 * @see int _on_segment_for_intersection(struct _point p, struct _point q, struct _point r)
 * 
 * @return (int) Returns 1 if the two line segments intersect. Returns 0 if the two line segments do not intersect.
 */
int my_check_2_line_intersection(struct _point p1, struct _point q1, struct _point p2, struct _point q2);

// Helper function for : my_check_2_line_intersection
int _orientation_for_intersection(struct _point p,struct _point q, struct _point r);

// Helper function for : my_check_2_line_intersection
int _on_segment_for_intersection(struct _point p, struct _point q, struct _point r);

// Lab 09 : Closest pair
/**
 * @brief The function iterates over all pairs of points to find the pair with the smallest distance between them. It uses the my_distance_btw_2_point function to calculate the distance between two points. It keeps track of the minimum distance found and the indices of the closest pair of points. It returns a dynamically allocated array containing the closest pair of points.
 * 
 * @param points (struct _point points[]) an array of _point structures representing the set of points
 * @param n (int) the number of points in the array.
 * 
 * @see float my_distance_btw_2_point(struct _point p1, struct _point p2)
 * 
 * @return (struct _point*) Returns a dynamically allocated array containing the closest pair of points
 */
struct _point* my_closest_pair_btw_multi_points(struct _point points[], int n);

// Helper function for : my_closest_pair_btw_multi_points
float my_distance_btw_2_point(struct _point p1, struct _point p2);

/* ------------------------ LAB 12 ------------------------ */ 

// Check convex or Concave
/**
 * @brief The function iterates over all pairs of points to find the pair with the smallest distance between them. It uses the my_distance_btw_2_point function to calculate the distance between two points. It keeps track of the minimum distance found and the indices of the closest pair of points. It returns a dynamically allocated array containing the closest pair of points.
 * 
 * @param points (struct _point points[]) an array of _point structures representing the set of points
 * @param n (int) the number of points in the array.
 * 
 * @return (int) Returns 1 if the polygon is convex. Returns 0 if the polygon is concave.
 */
int my_check_convex_concave(struct _point points[], int n);

#endif
