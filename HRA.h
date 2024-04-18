#ifndef HRA_H
#define HRA_H

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
float my_fractional_knapsack_greedy(int length, float weight[], float profit[], float knapsack);

// Helper function for : my_fractional_knapsack_greedy
void _sort_with_multiple_float_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order);

// Lab03 : Greedy Making change
void my_making_change_greedy(int length, int coins_array[], int capacity);

// Helper function for : my_making_change_greedy
void my_insertion_sort_for_integer_array(int arr[], int size, int order);

/* ------------------------ LAB 04 ------------------------ */ 

// Lab04 : 0/1 Knapsack Dynamic+Recursion
int my_01_knapsack_dynamic_recursion(int length, int weight[], int value[], int capacity, int **t);

// Helper function for : my_01_knapsack_dynamic_recursion
int** my_initialize_2d_dynamic_memory(int n, int m);

/* ------------------------ LAB 05 ------------------------ */ 

// Lab05 : Prim's algorithm
void my_prims_algorithm( int cost[], int parent[], int vertices, int graph[vertices][vertices] );

// Lab05 : Find string edit distance
int my_minimum_edit_string_distance(char *init_string, char *final_string, int init_length, int final_length, int **memo);

// Helper function for : my_minimum_edit_string_distance
int my_minimum_of_three_integer(int x, int y, int z);

/* ------------------------ LAB 06 ------------------------ */ 

// Lab06 : BFS traversal
void my_bfs_traversal(int start, int length, int graph[length][length], int parent[length]);

// Lab06 : DFS Traversal
void my_dfs_traversal(int start, int length, int **graph, int *parent);

/* ------------------------ LAB 07 ------------------------ */ 

// Lab07 : Topological Sort using DFS
void my_topological_sort_using_dfs(int length, int graph[length][length]);

// Helper function for : my_topological_sort_using_dfs
void _dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited);

// Lab07 : Topological sort using source removal
void my_topological_sort_using_source_removal(int length, int *indegree, int graph[length][length]);

// Helper function for : my_topological_sort_using_source_removal
void _deleted_node(int length, int node, int *indegree, int graph[length][length]);

// Helper function for : my_topological_sort_using_source_removal
void _find_indegree(int length, int graph[length][length], int *indegree);

// Lab07 : Find articulation point
void my_articulation_point(int length, int **graph, int V, int is_ap[]);

// Helper function for : my_articulation_point
int my_minimum_of_two_integer(int a, int b);

// Helper function for : my_articulation_point
void _DFS_to_find_articulation_point(int length, int **graph, int node, int visited[], int disc_time[], int lowest_disc_time[], int parent[], int is_ap[]);

#endif
