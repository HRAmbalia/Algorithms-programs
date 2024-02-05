// Fractional Knapsack Problem
/*  In the fractional knapsack problem, the items have both a value and a weight,
    and the goal is to maximize the value of the items while staying under a certain
    weight capacity. The difference with the classic knapsack problem is that the item
    can be divided into fractions which allows the algorithm to take a fraction of an item
    if it can't take the whole item. The algorithm will sort the item based on the value per
    weight ratio, and start taking the item with the highest value per weight ratio, until
    the knapsack is full.
*/

#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void _sort_with_multiple_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order) {
//     /*
//         Input: Integer length of array (All arrays should be of the same size and float type),
//                float array to sort by, float arrays to shuffle accordingly,
//                int order (0 for ascending, 1 for descending)
//         Output: Void
//         Explanation: This function performs sorting based on the specified order.
//         Requirement: None
//     */

//     if( order!=0 && order!=1 ) {
//         printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
//         return;
//     }

//     for( int i=1;i<length;i++ ) {
//         float current_value = sort_by_this_value[i];
//         int current_index = arr1[i];
//         float current_third_value = arr2[i];
//         int j = i-1;

//         while ( (order==0 && j>=0 && sort_by_this_value[j]>current_value) || (order==1 && j>=0 && sort_by_this_value[j]<current_value) ) {
//             sort_by_this_value[j+1] = sort_by_this_value[j];
//             arr1[j+1] = arr1[j];
//             arr2[j+1] = arr2[j];
//             j--;
//         }

//         sort_by_this_value[j+1] = current_value;
//         arr1[j+1] = current_index;
//         arr2[j+1] = current_third_value;
//     }
// }

// float my_fractional_knapsack_greedy(int length, float weight[], float profit[], float knapsack) {
//     /*
//         Input : integer length of array(length), float Capasity(knapsack), float array weight, float profit
//         Output : Float value(max profit)
//         Explaination : This function will use greedy method to find the max profit for knapsack problem.
//         Requirement : 
//             1.  Function named following : Which takes 1 integer length + 3 arrays as input, sorting is done based on the first array, Indices of array2 and array3 are shuffeled accordingly.
//                 void _sort_with_multiple_array(int length, float sort_by_this_value[], float arr1[], float arr2[], int order)

//     */

//     // Finding profit/weight ratio
//     float profit_by_weight[length];
//     for ( int i=0;i<length;i++ )
//         profit_by_weight[i] = profit[i] / weight[i];

//     // Sorting the array
//     _sort_with_multiple_array(length, profit_by_weight, weight, profit, 1);
    
//     float total = 0;
//     for ( int i=0;i<length;i++ ) {
//         if(weight[i]<=knapsack) {
//             total += profit[i];
//             knapsack -= weight[i];
//         }  
//         else {
//             total += ((knapsack/weight[i])*profit[i]);
//             knapsack -= (knapsack/weight[i]);
//         }
//     }
//     return total;
// }

int main() {
    // int n;
    // printf("Enter Array size : ");
    // scanf("%d", &n);
    int n = 7;

    // float weight[n];
    // printf("Enter Weight array :\n");
    // for( int i=0;i<n;i++ )
    //     scanf("%f", &weight[i]);
    float weight[] = {1, 3, 5, 4, 1, 3, 2};

    // float profit[n];
    // printf("Enter Profit array :\n");
    // for( int i=0;i<n;i++ )
    //     scanf("%f", &profit[i]);
    float profit[] = {5, 10, 15, 7, 8, 9, 4};

    // float kw;
    // printf("Enter knapsack capasity : ");
    // scanf("%f", &kw);
    float kw = 15;

    printf("Weight\t\t Profit\n");
    for ( int i=0;i<n;i++ ) {
        printf("%f\t%f\n", weight[i], profit[i]);
    }

    float max_weight = my_fractional_knapsack_greedy(n, weight, profit, kw);
    printf("Max Profit : %f\n", max_weight);

    return 0;
}