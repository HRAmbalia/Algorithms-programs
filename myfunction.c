#include "HRA.h" 
#include <stdio.h>
#include <stdlib.h>

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
float my_fractional_knapsack_greedy(int length, float weight[], float profit[], float knapsack) {
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

    // Finding profit/weight ratio
    float profit_by_weight[length];
    for ( int i=0;i<length;i++ )
        profit_by_weight[i] = profit[i] / weight[i];

    // Sorting the array
    _sort_with_multiple_float_array(length, profit_by_weight, weight, profit, 1);
    
    float total = 0;
    for ( int i=0;i<length;i++ ) {
        if(weight[i]<=knapsack) {
            total += profit[i];
            knapsack -= weight[i];
        }  
        else {
            total += ((knapsack/weight[i])*profit[i]);
            knapsack -= (knapsack/weight[i]);
        }
    }
    return total;
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

    if( order!=0 && order!=1 ) {
        printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
        return;
    }

    for( int i=1;i<length;i++ ) {
        float current_value = sort_by_this_value[i];
        int current_index = arr1[i];
        float current_third_value = arr2[i];
        int j = i-1;

        while ( (order==0 && j>=0 && sort_by_this_value[j]>current_value) || (order==1 && j>=0 && sort_by_this_value[j]<current_value) ) {
            sort_by_this_value[j+1] = sort_by_this_value[j];
            arr1[j+1] = arr1[j];
            arr2[j+1] = arr2[j];
            j--;
        }

        sort_by_this_value[j+1] = current_value;
        arr1[j+1] = current_index;
        arr2[j+1] = current_third_value;
    }
}

// Lab03 : Making change Greedy method
void my_making_change_greedy(int length, int coins_array[], int capacity) {
    /*
        Input : 
            length: The number of different types of coins available.
            coins_array[]: An array of integers representing the denominations of coins available.
            capacity: The amount for which change needs to be made.
        Output : 
            None
        Explanation : 
            This function calculates the change for a given amount using a greedy approach.
            It iterates through the coins_array[] from the highest denomination to the lowest,
            and at each step, it determines the maximum number of coins of that denomination that can be used
            without exceeding the capacity.
            It prints the number of coins of each denomination required to make the change.
    */


    // int count_of_coins = 0;
    int temp_value = 0;
    int cost = capacity;
    for (int i=0;i<length;i++ ) {
        if(coins_array[i]<=capacity) {
            int temp = capacity/coins_array[i];
            capacity -= temp*coins_array[i];
            printf("We need %d Coin of rupees %d = %d\n", temp, coins_array[i], (temp*coins_array[i]));
            temp_value += (temp*coins_array[i]);
            // count_of_coins++;
        }
    }
    if(temp_value<cost) {
        printf("Can generate change for %d only with given coin, %d is remaining.\n", temp_value, (cost-temp_value));
    }
}

// Helper function for : my_making_change_greedy
void my_insertion_sort_for_integer_array(int arr[], int size, int order) {
    /*
        Input: 
            arr[]: An array of integers to be sorted.
            size: The size of the array.
            order: Specifies the sorting order. Use 0 for ascending or 1 for descending.
        Output: 
            None
        Explanation: 
            This function sorts the array arr[] using the insertion sort algorithm.
            It sorts the array in either ascending or descending order, depending on the value of the 'order' parameter.
            If 'order' is 0, the array is sorted in ascending order.
            If 'order' is 1, the array is sorted in descending order.
    */

    if( order!=0 && order!=1 ) {
        printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
        return;
    }

    for( int i=1;i<size;i++ ) {
        int current = arr[i];
        int j = i-1;

        // Adjust the comparison based on the order parameter
        while( (order==0 && j>=0 && arr[j]>current) || (order==1 && j>= 0 && arr[j]<current) ) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

/* ------------------------------------- LAB 04 ------------------------------------- */

// Lab04 : 0/1 Knapsack problem Dynamic
int my_01_knapsack_dynamic_recursion(int length, int weight[], int value[], int capacity, int **t) {
    /*
        Input: 
            - length (int): The number of items available for the knapsack problem.
            - weight (int[]): An array representing the weight of each item.
            - value (int[]): An array representing the value of each item.
            - capacity (int): The maximum capacity of the knapsack.
            - t (int**): A 2D array (matrix) for memoization of computed results.
        Output: Returns the maximum value that can be obtained in the knapsack problem (int).
        Explanation: This function solves the 0/1 Knapsack problem using dynamic programming and memoization.
                      It takes the length of the items array, the weight and value arrays, the knapsack capacity,
                      and a memoization table as inputs. The function returns the maximum value that can be obtained
                      by selecting items to fit into the knapsack without exceeding its capacity.
    */

    if( capacity==0 || length==0 ) {
        return 0;
    }

    // If already computed, no need to compute again
    if(t[length][capacity]!=-1) {
        return t[length][capacity];
    }

    else if( weight[length-1]<=capacity ) {
        int temp1 = value[length-1] + my_01_knapsack_dynamic_recursion(length-1, weight, value, capacity-weight[length-1], t);
        int temp2 = my_01_knapsack_dynamic_recursion(length-1, weight, value, capacity, t);
        if(temp1<temp2) {
            t[length][capacity] = temp2;
            return temp2;
        }
        else{
            t[length][capacity] = temp1;
            return temp1;
        }
    }
    else if(weight[length-1]>capacity) {
        int temp2 = my_01_knapsack_dynamic_recursion(length-1, weight, value, capacity, t);
        t[length][capacity] = temp2;
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

