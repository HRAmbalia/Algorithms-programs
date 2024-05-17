#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int n = 5;
    int m = 50;
    int profit[] = {60, 100, 120, 80, 219};
    int weight[] = {10, 20, 30, 60, 49};
    int **t = my_initialize_2d_dynamic_memory(n, m);
    int selected_items[n];

    printf("Max Profit : %d\n", my_01_knapsack_dynamic_recursion(n, weight, profit, m, t, selected_items));

    int capacity = m;
    printf("Items added to the knapsack:\n");
    for(int i = n - 1; i >= 0 && capacity > 0; i--) {
        if (selected_items[i]) {
            printf("Item %d (weight = %d, profit = %d) is added\n", i + 1, weight[i], profit[i]);
            capacity -= weight[i];
        }
    }

    return 0;
}
