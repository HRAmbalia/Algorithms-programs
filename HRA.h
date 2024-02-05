#ifndef HRA_H
#define HRA_H

/* ------------------------ EXTRA ------------------------ */ 

// Simple summation of two integers
int addNumbers(int a, int b);

// Simple array printing function
void print_1d_array(int arr[], int size);

/* ------------------------ LAB 01 ------------------------ */ 

// Lab01 : Insertions Sort
void insertionSort(int arr[], int size);

// Lab01 : Magic Square
int** create_magic_square(int length);

/* ------------------------ LAB 02 ------------------------ */ 

// Lab02 : Merge Sort using recursion
void my_merge_sort_recursion(int arr[], int p, int r);

// Lab02 : Merge Sort using while
void my_merge_sort_while(int arr[], int length);

// Helper function for : merge_sort_recursion
void merge_for_recursion_while(int list[], int low, int mid, int high);

// Lab02 : Quick Sort using recursion
void my_quick_sort_recursion(int arr[], int low, int high);

// Lab02 : Quick Sort using while
void my_quick_sort_while(int arr[], int low, int high);

// Helper function for : temp_partition
void swap_two_variable(int *a, int *b);

// Helper function for : my_quick_sort
int temp_partition(int arr[], int low, int high);

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

int my_01_knapsack_dynamic(int length, int weight[], int value[], int capacity, int **t);
int** my_initialize_dynamic_memory(int n, int m);

#endif
