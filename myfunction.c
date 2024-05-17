#include "HRA.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define INT_MAX __INT_MAX__

#define INF 99999

// Demo Summation function
int addNumbers(int integer_01, int integer_02) {
    /*
        Input:
            - a (int): The first integer.
            - b (int): The second integer.
        Output:
            - Returns the sum of the two input integers (int).
        Explanation:
            This function takes two integers as input parameters and returns their sum.
            It provides a simple addition operation for integer values.
    */
    return integer_01 + integer_02;
}

// Print 1D array
void my_print_1d_integer_array(int arr[], int size) {
    /*
        Input: 
            - arr (int[]): 1D array to be printed.
            - size (int): Size of the array.
        Output: 
            - void (prints the elements of the array to the console).
        Explanation: 
            This function prints the elements of a 1D array to the console.
    */
    for (int i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Print 2D array
void my_print_2d_integer_array(int rows, int cols, int** arr) {
    /*
        Input:
            - rows (int): Number of rows in the 2D array.
            - cols (int): Number of columns in the 2D array.
            - arr (int**): Pointer to a 2D array.
        Output:
            - void (prints the 2D array to the console).
        Explanation:
            This function prints the elements of a 2D array to the console.
    */

    for( int i=0;i<rows;i++ ) {
        for( int j=0;j<cols;j++ ) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void my_print_2d_matrix(int n, int graph[n][n]) {
    /*
        Input:
            n (int): Size of the graph.
            graph (int[n][n]): 2D array representing the graph.
        Output:
            void (prints the graph to the console).
        Explanation:
            This function prints the elements of the graph (2D array) to the console.
    */

    // Iterate over each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

/* ------------------------------------- LAB 01 ------------------------------------- */

// Lab01 : Insertion Sort
void my_insertionSort_asc_for_integer_array(int integer_array[], int length_of_array) {
    /*
        Input: 
            - integer_array (int[]): An array of integers to be sorted.
            - length_of_array (int): The length of the integer_array.
        Output: 
            - void (The function sorts the input array in ascending order in-place).
        Explanation: 
            This function performs the insertion sort algorithm on the given integer array 
            in ascending order. It takes the input array and its length as parameters and 
            modifies the array in-place to achieve the sorted order.
    */
    for (int i=1;i<length_of_array;i++) {
        int current = integer_array[i];
        int j = i-1;

        while(integer_array[j]>current && j>=0) {
            integer_array[j+1] = integer_array[j];
            j--;
        }
        integer_array[j+1] = current;
    }
}

// Lab01 : Generate magic square
int** my_generate_magic_square(int length) {
    /*
        Input: 
            - length (int): The size of the magic square (number of rows or columns as it'll be square matrix).
        Output: 
            - Returns a dynamically allocated 2D array representing the magic square (int**).
        Explanation: 
            This function generates a magic square of order 'length' using the Siamese method. 
            It takes the size of the magic square as input and returns a dynamically allocated 2D array 
            representing the generated magic square.
    */

    int** mat = (int**)malloc(length*sizeof(int*));
    for (int i=0;i<length;i++) {
        mat[i] = (int*)malloc(length*sizeof(int));
    }

    int r = length;
    int c = length;
    int i, j, range;
    int count = 1;

    for (int i=0;i<length;i++) {
        for (int j=0;j<length;j++) {
            mat[i][j] = 0;
        }
    }

    range = r*c;
    i = 0;
    j = c/2;
    mat[i][j] = count;

    while(count<range) {
        count++;
        if(( (i-1)<0 || (i-1)>length-1) && ( (j-1)<0 || (j-1)>length-1) ) {
            i = i+1;
        }
        else if((i-1)<0 || (i-1)>length-1) {
            i = c-1;
            j = j-1;
        }
        else if((j-1)<0 || (j-1)>length-1) {
            j = c-1;
            i = i-1;
        }
        else if((mat[i-1][j-1]!=0)) {
            i = i+1;
        }
        else {
            i = i-1;
            j = j-1;
        }
        mat[i][j] = count;
    }
    return mat;
}

/* ------------------------------------- LAB 02 ------------------------------------- */

// Merge Sort Ascending using recursion
void my_merge_sort_asc_recursion(int arr[], int low, int high) {
    /*
        Input : 
            arr[]: An array of integers to be sorted.
            p: The starting index of the subarray to be sorted.
            r: The ending index of the subarray to be sorted.
        Output : 
            The array arr[] sorted in non-decreasing order.
        Explanation : 
            This function implements the recursive part of the merge sort algorithm.
            It recursively divides the input array into two halves until each subarray has only one element.
            Then it merges the sorted subarrays using the merge_for_recursion_while function.
    */

    int q;
    if (low < high) {
        q = (low + high) / 2;
        my_merge_sort_asc_recursion(arr, low, q);
        my_merge_sort_asc_recursion(arr, q+1, high);
        _merge_for_recursion_while(arr, low, q, high);
    }
}

// Merge Sort Ascending using while
void my_merge_sort_asc_while(int arr[], int length) {
     /*
        Input : 
            arr[]: An array of integers to be sorted.
            length: The number of elements in the array.
        Output : 
            The array arr[] sorted in non-decreasing order.
        Explanation : 
            This function implements the iterative version of the merge sort algorithm using a while loop.
            It divides the array into subarrays of increasing size and merges them in sorted order using the _merge_for_recursion_while function.
        Requirements : 
            1. Function : void _merge_for_recursion_while(int list[], int low, int mid, int high){...}
                Which does the merging for given array within given index
    */

    for (int i=1;i<=length-1;i=2*i) {
        for (int left_start=0;left_start<length-1;left_start+=2*i) {
            int mid = left_start+i-1;
            int right_end = (left_start+2*i-1<length-1) ? (left_start+2*i-1) : (length-1);
            _merge_for_recursion_while(arr, left_start, mid,right_end);
        }
    }
}

// Helper function for : my_merge_sort_asc_recursion
void _merge_for_recursion_while(int list[], int low, int mid, int high) {
    /*
        Input : 
            list[]: An array of integers to be merged.
            low: The starting index of the first subarray.
            mid: The ending index of the first subarray and the starting index of the second subarray.
            high: The ending index of the second subarray.
        Output : 
            The array list[] merged in non-decreasing order.
        Explanation : 
            This function merges two sorted subarrays list[low..mid] and list[mid+1..high] into a single sorted array.
            It uses a while loop to merge the elements in place without using extra memory.
    */

    int n1 = mid-low+1;
    int n2 = high-mid;
    int arr1[n1], arr2[n2];
    for (int i=0;i<n1;i++) {
        arr1[i] = list[low+i];
    }
    for (int i=0;i<n2;i++) {
        arr2[i] = list[mid+i+1];
    }

    int i=0,j=0,k=low;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            list[k] = arr1[i];
            i++;
        } else {
            list[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        list[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        list[k] = arr2[j];
        j++;
        k++;
    }
}


// Quick Sort Ascending using recursion
void my_quick_sort_asc_recursion(int integer_array[], int low, int high) {
    /*
        Input : 
            arr[]: An array of integers to be sorted.
            low: The starting index of the subarray to be sorted.
            high: The ending index of the subarray to be sorted.
        Output : 
            The array arr[] sorted in non-decreasing order.
        Explanation : 
            This function implements the recursive part of the quick sort algorithm.
            It selects a pivot element from the array and partitions the array such that elements smaller than the pivot are placed before it,
            and elements greater than the pivot are placed after it.
            Then, it recursively sorts the subarrays before and after the pivot.
        Requirements : 
            1. Function : int _temporary_partition(int arr[], int low, int high){...}
                Which returns the correct pivot position index.
    */
   
    if (low<high) {
        int pivot = _temporary_partition(integer_array, low, high);
        my_quick_sort_asc_recursion(integer_array, low, pivot-1);
        my_quick_sort_asc_recursion(integer_array, pivot+1, high);
    }
}

// Quick Sort Ascending using while
void my_quick_sort_asc_while(int integer_array[], int low, int high) {
    /*
        Input : integer_array[]: An array of integers to be sorted.
                low: The starting index of the subarray to be sorted.
                high: The ending index of the subarray to be sorted.
        Output : None
        Explanation : This function will sort the integer_array[] using recursion.
        Requirements : 
            1.  Function : int _temporary_partition(int arr[], int low, int high){...}
                Which returns the correct pivot position index.
    */
   
    int stack[high-low+1];
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int pivot = _temporary_partition(integer_array, low, high);
        if (pivot-1>=low) {
            stack[++top] = low;
            stack[++top] = pivot-1;
        }
        if (pivot+1<high) {
            stack[++top] = pivot+1;
            stack[++top] = high;
        }
    }
}

// Helper function for : _temporary_partition
void my_swap_two_variable(int *a, int *b) {
    /*
        Input : Pointers to two integer variables, a and b.
        Output : None
        Explanation : This function swaps the values of the variables pointed to by a and b.
    */

    int t = *a;
    *a = *b;
    *b = t;
}

// Helper function for : my_quick_sort_asc_while(Last element as PIVOT)
int _temporary_partition(int arr[], int low, int high) {
    /*
        Input : 
            arr[]: An array of integers to be partitioned.
            low: The starting index of the subarray to be partitioned.
            high: The ending index of the subarray to be partitioned.
        Output :
            Returns the index of the pivot element after partitioning.
        Explanation : 
            This function partitions the array into two halves around a pivot element.
            It selects the last element (arr[high]) as the pivot.
            Elements smaller than or equal to the pivot are moved to the left side of the pivot, and elements greater than the pivot are moved to the right side.
            Finally, it returns the index of the pivot element after partitioning.
        Requirements : 
            1.  function : void my_swap_two_variable(int *a, int *b){...}
                to swap two variables
    */

    int pivot = arr[high];
    int o = low-1;
    for (int i=low;i<high;i++) {
        if(arr[i]<=pivot) {
            o = o+1;
            my_swap_two_variable(&arr[o], &arr[i]);
        }
    }
    my_swap_two_variable(&arr[o+1], &arr[high]);
    return (o+1);
}

/* ------------------------------------- LAB 03 ------------------------------------- */

// Lab 03 : Knapsack problem
float my_fractional_knapsack_greedy(int length, float weight[], float profit[], float knapsack, float selected_weight[], float selected_profit[], float selected_fraction[]) {
    /*
        Input : 
            length: The number of items available.
            weight[]: An array of floats representing the weights of items.
            profit[]: An array of floats representing the profits of items.
            knapsack: The maximum weight the knapsack can hold.
        Output : 
            Returns the total profit obtained by selecting items optimally.
        Explanation : 
            This function solves the fractional knapsack problem using a greedy approach.
            It calculates the profit-to-weight ratio for each item, sorts the items based on this ratio,
            and selects items one by one until the knapsack is full.
            If an item cannot be selected completely, it takes a fractional part of it to maximize profit.
        Requirement : 
            1.  Function : void _sort_with_multiple_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order){...}
                Which takes 1 integer length + 3 arrays as input, sorting is done based on the first array, Indices of array2 and array3 are shuffeled accordingly.  
    */
    float profit_by_weight[length];
    for (int i = 0; i < length; i++)
        profit_by_weight[i] = profit[i] / weight[i];

    _sort_with_multiple_float_array(length, profit_by_weight, weight, profit, 1);

    float total_profit = 0;
    int idx = 0;

    for (int i = 0; i < length; i++) {
        if (weight[i] <= knapsack) {
            selected_weight[idx] = weight[i];
            selected_profit[idx] = profit[i];
            selected_fraction[idx] = 1.0;

            total_profit += profit[i];
            knapsack -= weight[i];
        } else {
            selected_weight[idx] = knapsack;
            selected_profit[idx] = (knapsack / weight[i]) * profit[i];
            selected_fraction[idx] = knapsack / weight[i];

            total_profit += selected_profit[idx];
            knapsack = 0;
        }
        idx++;
        if (knapsack <= 0)
            break;
    }

    return total_profit;
}

// Helper function for : Knapsack problem
void _sort_with_multiple_float_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order) {
    /*
        Input: 
            length: The length of arrays.
            sort_by_this_value[]: An array of floats to be sorted based on this value.
            arr1[]: Another array of floats to be rearranged along with sort_by_this_value[].
            arr2[]: Third array of floats to be rearranged along with sort_by_this_value[].
            order: Specifies the sorting order. Use 0 for ascending or 1 for descending.
        Output: 
            None
        Explanation:
            This function sorts the arrays arr1[] and arr2[] based on the values in sort_by_this_value[].
            It sorts the arrays in either ascending or descending order, depending on the value of the 'order' parameter.
    */
    if (order != 0 && order != 1) {
        printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
        return;
    }

    for (int i = 1; i < length; i++) {
        float current_value = sort_by_this_value[i];
        float current_weight = arr1[i];
        float current_profit = arr2[i];
        int j = i - 1;

        while ((order == 0 && j >= 0 && sort_by_this_value[j] > current_value) || 
               (order == 1 && j >= 0 && sort_by_this_value[j] < current_value)) {
            sort_by_this_value[j + 1] = sort_by_this_value[j];
            arr1[j + 1] = arr1[j];
            arr2[j + 1] = arr2[j];
            j--;
        }

        sort_by_this_value[j + 1] = current_value;
        arr1[j + 1] = current_weight;
        arr2[j + 1] = current_profit;
    }
}

// Lab03 : Making change Greedy method
int my_making_change_greedy(int length, int coins_array[], int capacity, int selected_coins[], int selected_counts[]) {
    /*
        Input:
            - int length: The number of different coin denominations available.
            - int coins_array[]: An array containing the values of the coin denominations.
            - int capacity: The total amount of money we need to make change for.
            - int selected_coins[]: An array to store the values of the coins used to make change.
            - int selected_counts[]: An array to store the counts of each coin used to make change.
        
        Output:
            - Returns the total value of change that was successfully generated using the available coins.
        
        Explanation:
            This function uses a greedy algorithm to determine the number of each type of coin needed to make change for the given capacity.
            It sorts the coins in descending order (from highest to lowest denomination) and iteratively selects the largest denomination coin that does not exceed the remaining capacity.
            The function updates the selected_coins and selected_counts arrays to reflect the coins used and their quantities.
            It returns the total value of the coins used to make change. If the total value is less than the original capacity, it means that exact change could not be generated with the given coin denominations.
    */
    int temp_value = 0;

    for (int i = 0; i < length; i++) {
        if (coins_array[i] <= capacity) {
            int temp = capacity / coins_array[i];
            capacity -= temp * coins_array[i];
            selected_coins[i] = coins_array[i];
            selected_counts[i] = temp;
            temp_value += (temp * coins_array[i]);
        }
    }

    return temp_value;
}

void my_insertion_sort_for_integer_array(int arr[], int size, int order) {
    /*
        Input:
            - int arr[]: The array of integers to be sorted.
            - int size: The number of elements in the array.
            - int order: The order of sorting, where 0 represents ascending order and 1 represents descending order.
        
        Output:
            - void: This function does not return a value. It sorts the input array in place.
        
        Explanation:
            This function performs an insertion sort on the input array based on the specified order.
            - If order is 0, the array is sorted in ascending order.
            - If order is 1, the array is sorted in descending order.
            The function first checks if the order parameter is valid. If it's not 0 or 1, an error message is printed.
            The insertion sort algorithm works by iterating through the array and at each iteration, 
            placing the current element in its correct position relative to the already sorted portion of the array.
            The comparison logic within the while loop is adjusted based on the order parameter to achieve the desired sorting order.
    */
    if ( order!=0 && order!=1 ) {
        printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
        return;
    }

    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i-1;

        // Adjust the comparison based on the order parameter
        while ((order == 0 && j >= 0 && arr[j] > current) || (order == 1 && j >= 0 && arr[j] < current)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

/* ------------------------------------- LAB 04 ------------------------------------- */

// Lab04 : 0/1 Knapsack problem Dynamic
int my_01_knapsack_dynamic_recursion(int length, int weight[], int value[], int capacity, int **t, int *selected_items) {
    /*
        Input: 
            - length (int): The number of items available for the knapsack problem.
            - weight (int[]): An array representing the weight of each item.
            - value (int[]): An array representing the value of each item.
            - capacity (int): The maximum capacity of the knapsack.
            - t (int**): A 2D array (matrix) for memoization of computed results.
            - selected_items (int[]): An array to store whether an item is selected or not.
        Output: Returns the maximum value that can be obtained in the knapsack problem (int).
        Explanation: This function solves the 0/1 Knapsack problem using dynamic programming and memoization.
                      It takes the length of the items array, the weight and value arrays, the knapsack capacity,
                      a memoization table, and an array to store selected items as inputs. The function returns the maximum value 
                      that can be obtained by selecting items to fit into the knapsack without exceeding its capacity.
    */

    if( capacity==0 || length==0 ) {
        return 0;
    }

    // If already computed, no need to compute again
    if(t[length][capacity]!=-1) {
        return t[length][capacity];
    }

    else if( weight[length-1]<=capacity ) {
        int temp1 = value[length-1] + my_01_knapsack_dynamic_recursion(length-1, weight, value, capacity-weight[length-1], t, selected_items);
        int temp2 = my_01_knapsack_dynamic_recursion(length-1, weight, value, capacity, t, selected_items);
        if(temp1<temp2) {
            t[length][capacity] = temp2;
            selected_items[length-1] = 0; // Item not selected
            return temp2;
        }
        else{
            t[length][capacity] = temp1;
            selected_items[length-1] = 1; // Item selected
            return temp1;
        }
    }
    else if(weight[length-1]>capacity) {
        int temp2 = my_01_knapsack_dynamic_recursion(length-1, weight, value, capacity, t, selected_items);
        t[length][capacity] = temp2;
        selected_items[length-1] = 0; // Item not selected
        return temp2;
    }
}

// Function to generate dynamic_memory of size n*m
int** my_initialize_2d_dynamic_memory(int n, int m) {
    /*
        Input: 
            - n (int): Integer representing the number of rows in the 2D array (matrix).
            - m (int): Integer representing the number of columns in the 2D array (matrix).
        Output: Returns a dynamically allocated 2D array (matrix) (int**).
        Explanation: This function initializes a 2D array (matrix) of size (n+1) x (m+1) and sets all elements to -1.
                      The matrix is dynamically allocated using malloc, and the function returns a pointer to the allocated memory.
    */

    int** t = (int **)malloc((n+1) * sizeof(int *));
    for(int i=0;i<=n;i++ ) {
        t[i] = (int *)malloc((m+1) * sizeof(int));
        for( int j=0;j<=m;j++ ) {
            t[i][j] = -1;
        }
    }
    return t;
}

/* ------------------------------------- LAB 05 ------------------------------------- */

// Lab05 : Prim's algorithm
void my_prims_algorithm(int cost[], int parent[], int vertices, int graph[vertices][vertices] ) {
    /*
        Input:
            cost[]: (Integer array) to store the minimum cost to reach each vertex from the starting vertex
            parent[]: (Integer array) to store the parent of each vertex in the minimum spanning tree
            vertices: (Integer) number of vertices in the graph
            graph[][]: (2D Integer array)adjacency matrix representing the weighted graph
        
        Output:
            None - Updates graph[][] and parent[] passed as argument by the user.
        
        Explanation:
            For start node = 0
            This function implements Prim's algorithm to find the minimum spanning tree of a weighted undirected graph.
            Prim's algorithm grows a single tree (or forest) by adding vertices to the minimum spanning tree one at a time, starting from an arbitrary vertex.
            At each step, it selects the edge with the minimum weight that connects a vertex in the minimum spanning tree to a vertex outside of it.
            The function updates the cost array with the minimum cost to reach each vertex and the parent array with the parent of each vertex in the minimum spanning tree.
    */
    int start = 0;
    cost[start] = 0;
    parent[start] = -1;
    int isVisited[vertices];
    for( int i=0;i<vertices;i++ ) {
        isVisited[i] = 0;
    }

    for( int v=0;v<vertices-1;v++ ) {
        int minCost = INF, minIndex;
        for( int i=0;i<vertices;i++ )  {
            if( isVisited[i]==0 && cost[i]<minCost ) {
                minCost = cost[i];
                minIndex = i;
            }
        }

        isVisited[minIndex] = 1;

        for( int i=0;i<vertices;i++ ) {
            if (graph[minIndex][i] && isVisited[i]==0 && graph[minIndex][i]<cost[i] ) {
                parent[i] = minIndex;
                cost[i] = graph[minIndex][i];
            }
        }
    }
}

// Lab05 : Find minimum string edit distance
int my_minimum_edit_string_distance(char *init_string, char *final_string, int init_length, int final_length, int **memo) {

    /*
        Input:
            - init_string: Pointer to the initial string (character array).
            - final_string: Pointer to the final string (character array).
            - init_length: Length of the initial string.
            - final_length: Length of the final string.
            - memo: Pointer to a 2D integer array used for memoization (optional for efficiency).

        Output:
            - The minimum number of edit operations (insertions, deletions, or replacements) required to transform the initial string into the final string.

        Explanation:
            This function implements a dynamic programming (DP) approach to calculate the edit distance between two strings. It considers three operations:
                - Insertion: Insert a character into the initial string.
                - Deletion: Delete a character from the initial string.
                - Replacement: Replace a character in the initial string.

            The function works by recursively breaking down the problem into smaller subproblems. It uses memoization (optional) to store previously computed results and avoid redundant calculations.
    */

    // Base cases
    if (init_length == 0)
        return final_length;
    if (final_length == 0)
        return init_length;

    // If already computed, return memoized value
    if (memo[init_length][final_length] != -1)
        return memo[init_length][final_length];

    // If last characters are same, ignore last characters and recur for remaining strings
    if (init_string[init_length - 1] == final_string[final_length - 1])
        return memo[init_length][final_length] = my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length-1, memo);

    // If last characters are not same, consider all three operations
    return memo[init_length][final_length] = 1 + my_minimum_of_three_integer(
        my_minimum_edit_string_distance(init_string, final_string, init_length, final_length-1, memo), // Insert
        my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length, memo), // Remove
        my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length-1, memo) // Replace
    );
}

// Helper function for : my_minimum_edit_string_distance
int my_minimum_of_three_integer(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

/* ------------------------------------- LAB 06 ------------------------------------- */

// Lab06 : BFS traversal
void my_bfs_traversal(int start, int length, int graph[length][length], int *parent, int traversal_order[length]) {
    /*
        Input:
            - start: The starting node for the BFS traversal (integer).
            - length: The number of vertices in the graph (integer).
            - graph: A 2D integer array representing the adjacency matrix of the graph. `graph[i][j]` indicates an edge between node `i` and node `j` (1 or 0).
            - parent: A 1D integer array to store the parent node for each visited node during the BFS traversal (used for path reconstruction if needed).
            - traversal_order : A 1D integer array which stores traversal order.

        Output:
            - The function performs a Breadth-First Search (BFS) traversal on the provided graph starting from the `start` node.
            - It prints the visited nodes and the queue contents at each step for visualization (can be removed for a cleaner output).

        Explanation:
            This function implements a Breadth-First Search (BFS) algorithm to explore a connected graph. It uses a queue to maintain the order of node exploration.
    */

    int queue[(length*(length-1))/2];
    int front = 0;
    int rear = -1;
    int visited[9];
    for( int i=0;i<length;i++ ) 
        visited[i] = 0; 

    rear++;
    queue[rear] = start;
    visited[start] = 1;
    int orderIndex = 0;

    while( front<=rear ) {

        // printf("\nVisited array: ");
        // print_1d_integer_array(visited, length);

        // printf("Queue : ");
        // for( int i=front;i<=rear;i++ ) {
        //     printf("%d ", queue[i]+1);
        // }
        // printf("\n");

        int current = queue[front++];
        traversal_order[orderIndex++] = current+1;
        // printf("Visiting node(front of the queue) : %d\n", current+1);

        // Explore adjacent nodes of current
        for( int i=0;i<length;i++ ) {
            if( graph[current][i] && !visited[i] ) {
                rear++;
                queue[rear] = i; // Add adjacent nodes to the queue
                visited[i] = 1; // Node is now visited
                parent[i] = current;// As we reached from curent to this node
                // printf("Adding edge: (%d, %d)\n", current+1, i+1);
            }
        }
    }
}

// Lab06 : DFS traversal
void my_dfs_traversal(int start, int length, int **graph, int *parent, int *traversal_order) {
    /*
        Input:
            - start: The starting node for the DFS traversal (integer).
            - length: The number of vertices in the graph (integer).
            - graph: A 2D integer array representing the adjacency matrix of the graph. `graph[i][j]` indicates an edge between node `i` and node `j` (1 or 0).
            - parent: A 1D integer array to store the parent node for each visited node during the DFS traversal (used to generate DFS spanning tree).
            - traversal_order : A 1D integer array which stores traversal order.

        Output:
            - None - The function updates the traversal_order[] array and parent[] array which is passed as argument, stores traversal order and parent for each node in DFS tree.

        Explanation:
            This function implements a Depth-First Search (DFS) algorithm to explore a connected graph. It uses a stack to maintain the order of node exploration.
    */
    int stack[length*2];
    int top = -1;
    int visited[length];

    for (int i = 0; i < length; i++) {
        visited[i] = 0;
    }

    stack[++top] = start;
    visited[start] = 1; 
    while (top != -1) {
        int current = stack[top--];
        *traversal_order++ = current;

        for (int i = length - 1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1; // Mark adjacent node as visited
                parent[i] = current; // Update parent
            }
        }
    }
}

/* ------------------------------------- LAB 07 ------------------------------------- */

// Helper function for : my_topological_sort_using_dfs
void _dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited, int topological_sort[length]) {
    /*
        Input: 
            - start: The starting node for DFS traversal.
            - length: The number of nodes in the graph.
            - graph: A 2D array representing the graph's adjacency matrix.
            - global_visited: An array indicating nodes visited across different invocations.
            - topological_sort: An array to store the topological ordering.
        Output: None (Output is printed directly)
        Explanation: Performs Depth-First Search (DFS) traversal on a graph represented by an adjacency matrix.
        Requirement : This function is required for another function, `my_topological_sort_using_dfs`,
            which depends on this function being defined.
    */
    int visited[length];
    for( int i=0;i<length;i++ ) {
        visited[i] = global_visited[i];
    }
    int stack[(length*(length-1))/2];
    int top = -1;
    top++;
    stack[top] = start;
    visited[start] = 1;
    while( top!=-1 ) {
        int current = stack[top];
        // printf("Visiting node : %d\n", current+1);
        top--;
        for( int i=0;i<length;i++ ) {
            if (graph[current][i] && !visited[i]) {
                top++;
                stack[top] = i; // Add adjecent nodes to stack
                visited[i] = 1; // Node is now visited
                // printf("Adding node %d to stack\n", i+1);
            }
        }
        topological_sort[current] = current + 1; // Add current node to topological sort array
    }
    for( int i=0;i<length;i++ ) {
        global_visited[i] = visited[i];
    }
}

// Lab 07 : 
void my_topological_sort_using_dfs(int length, int graph[length][length], int topological_sort[length]) {
    /*
        Input: 
            - length: the number of nodes in the graph
            - graph: a 2D array representing the adjacency matrix of the graph
                     where graph[i][j] = 1 if there is an edge from node i to node j, 0 otherwise
        Output: 
        Explanation: 
            - This function performs a topological sort on a directed acyclic graph (DAG) using depth-first search (DFS).
            - It prints the nodes in the order they are visited during DFS, which represents a topological ordering.
        Requirement : 
            - The graph must be represented using an adjacency matrix.
            - Another function '_dfs_for_topological_sort(int start, int length, int graph[length][length], int *global_visited)' is required as helper function for this program
    */
    int global_visited[length];
    for( int i=0;i<length;i++ )
        global_visited[i] = 0;
    for( int i=0;i<length;i++ ) {
        if( global_visited[i]==0 ) {
            // printf("\nStarting DFS from node %d\n", i+1);
            _dfs_for_topological_sort(i, length, graph, global_visited, topological_sort);
        }
    }
}

void my_find_indegree(int length, int graph[length][length], int *indegree) {
    /*
        Input : 
            - length: the number of nodes in the graph
            - graph: a 2D array representing the adjacency matrix of the graph
            - indegree: an array representing the indegree of each node in the graph
                      (modified in this function)
        Output : None
        Explanation : 
            - This function calculates the indegree of each node in the graph.
        Requirement : None
    */
    for( int i=0;i<length;i++ ) {
        for( int j=0;j<length;j++ ) {
            if( graph[i][j]==1 ) {
                indegree[j]++;
            }
        }
    }
}

void _deleted_node(int length, int node, int *indegree, int graph[length][length]) {
    /*
        Input : 
            - length: the number of nodes in the graph
            - node: the node to be deleted
            - indegree: an array representing the indegree of each node in the graph
                      (modified in this function)
            - graph: a 2D array representing the adjacency matrix of the graph
                     (modified in this function)
        Output : 
        Explanation : 
            This function updates the indegree array and the graph by removing edges incident on the given node.
        Requirement : None
    */
    for( int i=0;i<length;i++ ) {
        if(graph[node][i]==1) {
            indegree[i]--;
        }
    }
}

void my_topological_sort_using_source_removal(int length, int *indegree, int graph[length][length], int topological_sort[length]) {
    /*
        Input : 
            - length: the number of nodes in the graph
            - indegree: an array representing the indegree of each node in the graph
            - graph: a 2D array representing the adjacency matrix of the graph
                     where graph[i][j] = 1 if there is an edge from node i to node j, 0 otherwise
            - topological_sort: An array to store the topological ordering.
        Output : 
        Explanation : 
            - This function performs a topological sort on a directed acyclic graph (DAG) using the source removal algorithm.
            - It deletes nodes with indegree 0 iteratively until all nodes are visited.
        Requirement : 
            - _deleted_node(int length, int node, int *indegree, int graph[length][length]) must be defined which will modify the indegree array and update the graph by removing edges.
            - void my_find_indegree(int length, int graph[length][length], int *indegree) must be defined which will calculate the indegree of each node in the graph.
    */

    int visited[length];
    for( int i=0;i<length;i++ ) {
        visited[i] = 0;
    }
    int index = 0;

    while(1) {
        int temp = 0;
        for( int i=0;i<length;i++ ) {
            if(indegree[i]==0 && visited[i]==0){
                // printf("deleting node : %d\n", i+1);
                _deleted_node(length, i, indegree, graph);
                visited[i] = 1;
                topological_sort[index++] = i + 1; // Add current node to topological sort array
                temp = 1;
            }
        }
        if(temp==0) {
            break;
        }
    }
}

// Lab07 : Find Articulation Point
void my_articulation_point(int length, int **graph, int is_ap[]) {
    /*
        Input :
            - length: The number of verices in the graph.
            - graph: An adjacency matrix representing the graph.
            - is_ap[]: An array to mark nodes as articulation points.
        Output :
            No explicit output. The function updates the is_ap[] array to mark articulation points.
        Explanation : 
            This function identifies articulation points (AP) in a graph using Depth First Search (DFS).
            It initializes arrays for tracking visited nodes, discovery times, lowest discovery times, and parent nodes.
            Then, it iterates through each vertex in the graph, performing DFS if the vertex is not already visited.
            The DFS function (_DFS_to_find_articulation_point) is called for each unvisited vertex to identify articulation points.
        Requirement : 
            - function _DFS_to_find_articulation_point(length, graph, i, visited, disc_time, lowest_disc_time, parent, is_ap) which is used to perform DFS to find articulation points.
    */
    int visited[length];
    int disc_time[length];
    int lowest_disc_time[length];
    int parent[length];
    
    for( int i=0;i<length;i++ ) {
        parent[i] = -1;
        visited[i] = false;
        is_ap[i] = false;
    }
    
    for( int i=0;i<length;i++ )
        if (!visited[i])
            _DFS_to_find_articulation_point(length, graph, i, visited, disc_time, lowest_disc_time, parent, is_ap);
}

// Helper function for : my_articulation_point
int my_minimum_of_two_integer(int a, int b) {
    return (a<b) ? a:b;
}

// Helper function for : my_articulation_point
void _DFS_to_find_articulation_point(int length, int **graph, int node, int visited[], int disc_time[], int lowest_disc_time[], int parent[], int is_ap[]) {
    /*
        Input:
            - length: The number of nodes in the graph.
            - graph: An adjacency matrix representing the graph.
            - node: The current node being visited during DFS traversal.
            - visited[]: An array to keep track of visited nodes.
            - disc_time[]: An array to store the discovery time of each node.
            - lowest_disc_time[]: An array to store the lowest discovery time reachable from each node.
            - parent[]: An array to store the parent of each node in the DFS traversal tree.
            - is_ap[]: An array to mark nodes as articulation points.
            
        Output:
            No explicit output. The function updates various arrays (disc_time[], lowest_disc_time[], parent[], is_ap[]) to store information about the graph and articulation points.
        
        Explanation:
            - This function implements Depth First Search (DFS) to traverse a graph and identify articulation points (AP).
            - It starts by initializing some variables and marking the current node as visited.
            - Then, it updates the discovery time and lowest discovery time of the current node.
            - The function iterates over all adjacent nodes of the current node.
                - If an adjacent node is not visited, it recursively calls DFS on that node, marking the current node as its parent.
                - It updates the lowest discovery time of the current node based on the child's lowest discovery time.
                - If the current node is the root of the DFS tree and has more than one child, it's marked as an articulation point.
                - If the current node is not the root and the lowest discovery time of the child is greater than or equal to the discovery time of the current node, it's marked as an articulation point.
                - If the adjacent node is already visited and not the parent of the current node, it updates the lowest discovery time of the current node based on the adjacent node's discovery time.
            - The function does not return any explicit value but updates various arrays to reflect the DFS traversal and identify articulation points.
    */

    static int time = 0;
    int children = 0;
    visited[node] = 1;
    disc_time[node] = lowest_disc_time[node] = ++time;
    
    // printf("\nVisiting node %d\n", node);
    // printf("Updated disc_time[%d] = %d\n", node, disc_time[node]);
    // printf("Updated lowest_disc_time[%d] = %d\n", node, lowest_disc_time[node]);

    for( int v=0;v<length;v++ ) {
        if( graph[node][v] ) {
            if ( !visited[v] ) {
                children++;
                parent[v] = node;
                // printf("DFS from %d to %d\n", node, v);
                _DFS_to_find_articulation_point(length, graph, v, visited, disc_time, lowest_disc_time, parent, is_ap);
                // printf("Returned from DFS from %d to %d\n", node, v);
                lowest_disc_time[node] = my_minimum_of_two_integer(lowest_disc_time[node], lowest_disc_time[v]);
                // printf("Updated lowest_disc_time[%d] = %d\n", node, lowest_disc_time[node]);
                if( parent[node]==-1 && children>1 ) {
                    is_ap[node] = 1;
                    // printf("Articulation point found: %d\n", node);
                }
                if( parent[node]!=-1 && lowest_disc_time[v]>=disc_time[node] ) {
                    is_ap[node] = 1;
                    // printf("Articulation point found: %d\n", node);
                }
            }
            else if( v!=parent[node] ) {
                lowest_disc_time[node] = my_minimum_of_two_integer(lowest_disc_time[node], disc_time[v]);
                // printf("Back edge found between %d and %d\n", node, v);
                // printf("Updated lowest_disc_time[%d] = %d\n", node, lowest_disc_time[node]);
            }
        }
    }
}

/* ------------------------------------- LAB 08 ------------------------------------- */

// Helper Function for : my_dijkstra
int _mindist ( int dist[], bool check[], int V ) {
    /*
        Input : 
            - dist[]: An array storing the shortest distance of vertices from the source vertex.
            - check[]: An array representing whether a vertex is included in the shortest path tree or not.
            - V: Number of vertices in the graph.
        Output : 
            - Returns the index of the vertex with the minimum distance value, which is not yet included in the shortest path tree.
        Explanation : 
            This function iterates through all the vertices not yet included in the shortest path tree and returns the index of the vertex with the minimum distance value. 
    */

    int min = INT_MAX, minindex;
    for ( int i=0;i<V;i++ )
        if ( check[i]==false && dist[i]<=min ) {
            min = dist[i]; // update when min is greater than dist recorded
            minindex = i;
        }
    return minindex;
}

// Lab 08 : Dijkstra's algorithm to fincd shortest path
void my_dijkstra(int V, int arr[V][V], int src, int dist[V]) {
    /*
        Input : 
            - V: Number of vertices in the graph.
            - arr[][]: Adjacency matrix representing the graph.
            - src: Source vertex.
            - dist[]: An array to store the shortest distance from the source vertex to every other vertex.
        Output : None, output will be copied to array passed by user as last argument. 
        Explanation : 
            This function implements Dijkstra's algorithm to find the shortest path from a given source vertex to all other vertices in the graph.
        Requirement : 
            Function : int _mindist ( int dist[], bool check[], int V ) -> Which returns the index of the minimum valued node 
    */

    bool check[V]; // check[i] will true if vertex i is included in shortest path
    for ( int i=0;i<V;i++ ) {
        check[i] = false;
    }
    dist[src] = 0; // cause starting node
    for ( int i=0;i<V-1;i++ ) {
        int min = _mindist(dist, check, V); // pick the minimum distance vertex.
        check[min] = true; // mark the picked vertex as processed
        for ( int j=0;j<V;j++ )
            if ( !check[j] && arr[min][j] && dist[min]!=INT_MAX && dist[min]+arr[min][j]<dist[j] )
                dist[j] = dist[min]+arr[min][j]; // update dist[v] by shortest distance
    }
}

// Lab 08 : Floyd Warshell algorithm
void my_floydWarshall_algo(int n, int graph[n][n]) {
    /*
        Input :
            - n: Number of vertices in the graph.
            - graph[][]: Adjacency matrix representing the graph.
        Output : None, Output will be updated in passed 2D array itself.
        Explanation : 
            This function implements the Floyd Warshall algorithm to find the shortest distances between every pair of vertices in a weighted graph.
    */

    for ( int k=0;k<n;k++ ) {
        for ( int i=0;i<n;i++ ) {
            for ( int j=0;j<n;j++ ) {
                if (graph[i][j] > graph[i][k]+graph[k][j] ) {
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
}
