// Making a Change Problem

#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"



// void my_insertion_sort(int arr[], int size, int order) {
//     /*
//         Input: integer Array, Integer length of the array, Integer order (0 for ascending, 1 for descending)
//         Output: void
//         Explanation: This function will sort the given array based on the specified order.
//     */

//     if( order!=0 && order!=1 ) {
//         printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
//         return;
//     }

//     for( int i=1;i<size;i++ ) {
//         int current = arr[i];
//         int j = i-1;

//         // Adjust the comparison based on the order parameter
//         while( (order==0 && j>=0 && arr[j]>current) || (order==1 && j>= 0 && arr[j]<current) ) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = current;
//     }
// }

// void my_making_change_greedy(int length, int coins_array[], int capacity) {
//     /*
//         Input : Integer length of array(length), Integer array(coins_array), Integer Capacity
//         Output : Void
//         Explaination : This Function will use the greedy method to print the changes
//     */

//     // int count_of_coins = 0;
//     int temp_value = 0;
//     int cost = capacity;
//     for (int i=0;i<length;i++ ) {
//         if(coins_array[i]<=capacity) {
//             int temp = capacity/coins_array[i];
//             capacity -= temp*coins_array[i];
//             printf("We need %d Coin of rupees %d = %d\n", temp, coins_array[i], (temp*coins_array[i]));
//             temp_value += (temp*coins_array[i]);
//             // count_of_coins++;
//         }
//     }
//     if(temp_value<cost) {
//         printf("Can generate change for %d only with given coin, %d is remaining.\n", temp_value, (cost-temp_value));
//     }
// }


int main() {
    int length = 5;
    int coins_array[] = {2, 5, 10, 25, 50};
    int capacity = 141;
    printf("capacity : %d\n", capacity);
    printf("coin Are : ");
    for( int i=0;i<length;i++ ) {
        printf("%d ", coins_array[i]);
    }
    printf("\n");
    // insertionSortDescending(coins_array, length);
    my_insertion_sort_for_integer_array(coins_array, length, 1);
    my_making_change_greedy(length, coins_array, capacity);

    return 0;
}
