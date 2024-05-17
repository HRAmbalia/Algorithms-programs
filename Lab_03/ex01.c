#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"


// Function to sort arrays based on a key array, supporting both ascending and descending order.
// void _sort_with_multiple_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order) {
//     /*
//         Input: 
//             length: The length of arrays.
//             sort_by_this_value[]: An array of floats to be sorted based on this value.
//             arr1[]: Another array of floats to be rearranged along with sort_by_this_value[].
//             arr2[]: Third array of floats to be rearranged along with sort_by_this_value[].
//             order: Specifies the sorting order. Use 0 for ascending or 1 for descending.
//         Output: 
//             None
//         Explanation:
//             This function sorts the arrays arr1[] and arr2[] based on the values in sort_by_this_value[].
//             It sorts the arrays in either ascending or descending order, depending on the value of the 'order' parameter.
//     */
//     if (order != 0 && order != 1) {
//         printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
//         return;
//     }

//     for (int i = 1; i < length; i++) {
//         float current_value = sort_by_this_value[i];
//         float current_weight = arr1[i];
//         float current_profit = arr2[i];
//         int j = i - 1;

//         while ((order == 0 && j >= 0 && sort_by_this_value[j] > current_value) || 
//                (order == 1 && j >= 0 && sort_by_this_value[j] < current_value)) {
//             sort_by_this_value[j + 1] = sort_by_this_value[j];
//             arr1[j + 1] = arr1[j];
//             arr2[j + 1] = arr2[j];
//             j--;
//         }

//         sort_by_this_value[j + 1] = current_value;
//         arr1[j + 1] = current_weight;
//         arr2[j + 1] = current_profit;
//     }
// }

// // Greedy algorithm for the fractional knapsack problem, with added arrays to store the selection details.
// float my_fractional_knapsack_greedy(int length, float weight[], float profit[], float knapsack, float selected_weight[], float selected_profit[], float selected_fraction[]) {
//     /*
//         Input : 
//             length: The number of items available.
//             weight[]: An array of floats representing the weights of items.
//             profit[]: An array of floats representing the profits of items.
//             knapsack: The maximum weight the knapsack can hold.
//         Output : 
//             Returns the total profit obtained by selecting items optimally.
//         Explanation : 
//             This function solves the fractional knapsack problem using a greedy approach.
//             It calculates the profit-to-weight ratio for each item, sorts the items based on this ratio,
//             and selects items one by one until the knapsack is full.
//             If an item cannot be selected completely, it takes a fractional part of it to maximize profit.
//         Requirement : 
//             1.  Function : void _sort_with_multiple_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order){...}
//                 Which takes 1 integer length + 3 arrays as input, sorting is done based on the first array, Indices of array2 and array3 are shuffeled accordingly.  
//     */
//     float profit_by_weight[length];
//     for (int i = 0; i < length; i++)
//         profit_by_weight[i] = profit[i] / weight[i];

//     _sort_with_multiple_array(length, profit_by_weight, weight, profit, 1);

//     float total_profit = 0;
//     int idx = 0;

//     for (int i = 0; i < length; i++) {
//         if (weight[i] <= knapsack) {
//             selected_weight[idx] = weight[i];
//             selected_profit[idx] = profit[i];
//             selected_fraction[idx] = 1.0;

//             total_profit += profit[i];
//             knapsack -= weight[i];
//         } else {
//             selected_weight[idx] = knapsack;
//             selected_profit[idx] = (knapsack / weight[i]) * profit[i];
//             selected_fraction[idx] = knapsack / weight[i];

//             total_profit += selected_profit[idx];
//             knapsack = 0;
//         }
//         idx++;
//         if (knapsack <= 0)
//             break;
//     }

//     return total_profit;
// }

int main() {
    int n = 7;
    float weight[] = {1, 3, 5, 4, 1, 3, 2};
    float profit[] = {5, 10, 15, 7, 8, 9, 4};
    float kw = 11;

    float selected_weight[n];
    float selected_profit[n];
    float selected_fraction[n];

    printf("Weight\t\t Profit\n");
    for (int i = 0; i < n; i++) {
        printf("%f\t%f\n", weight[i], profit[i]);
    }

    float max_profit = my_fractional_knapsack_greedy(n, weight, profit, kw, selected_weight, selected_profit, selected_fraction);

    printf("Max Profit: %f\n", max_profit);
    printf("Selected Items:\n");
    printf("Weight\t\tProfit\t\tFraction\n");
    for (int i = 0; i < n; i++) {
        if (selected_fraction[i] > 0) {
            printf("%f\t%f\t%f\n", selected_weight[i], selected_profit[i], selected_fraction[i]);
        }
    }

    return 0;
}
