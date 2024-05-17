#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// Function to sort an array using insertion sort, with a specified order (ascending or descending).
// void my_insertion_sort_for_integer_array(int arr[], int size, int order) {
//     /*
//         Input:
//             - int arr[]: The array of integers to be sorted.
//             - int size: The number of elements in the array.
//             - int order: The order of sorting, where 0 represents ascending order and 1 represents descending order.
        
//         Output:
//             - void: This function does not return a value. It sorts the input array in place.
        
//         Explanation:
//             This function performs an insertion sort on the input array based on the specified order.
//             - If order is 0, the array is sorted in ascending order.
//             - If order is 1, the array is sorted in descending order.
//             The function first checks if the order parameter is valid. If it's not 0 or 1, an error message is printed.
//             The insertion sort algorithm works by iterating through the array and at each iteration, 
//             placing the current element in its correct position relative to the already sorted portion of the array.
//             The comparison logic within the while loop is adjusted based on the order parameter to achieve the desired sorting order.
//     */
//     if ( order!=0 && order!=1 ) {
//         printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
//         return;
//     }

//     for (int i=1;i<size;i++ ) {
//         int current = arr[i];
//         int j = i-1;

//         // Adjust the comparison based on the order parameter
//         while ((order == 0 && j >= 0 && arr[j] > current) || (order == 1 && j >= 0 && arr[j] < current)) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = current;
//     }
// }

// // Greedy algorithm for making change, storing the results in arrays passed by reference.
// int my_making_change_greedy(int length, int coins_array[], int capacity, int selected_coins[], int selected_counts[]) {
//     /*
//         Input:
//             - int length: The number of different coin denominations available.
//             - int coins_array[]: An array containing the values of the coin denominations.
//             - int capacity: The total amount of money we need to make change for.
//             - int selected_coins[]: An array to store the values of the coins used to make change.
//             - int selected_counts[]: An array to store the counts of each coin used to make change.
        
//         Output:
//             - Returns the total value of change that was successfully generated using the available coins.
        
//         Explanation:
//             This function uses a greedy algorithm to determine the number of each type of coin needed to make change for the given capacity.
//             It sorts the coins in descending order (from highest to lowest denomination) and iteratively selects the largest denomination coin that does not exceed the remaining capacity.
//             The function updates the selected_coins and selected_counts arrays to reflect the coins used and their quantities.
//             It returns the total value of the coins used to make change. If the total value is less than the original capacity, it means that exact change could not be generated with the given coin denominations.
//     */
//     int temp_value = 0;

//     for (int i = 0; i < length; i++) {
//         if (coins_array[i] <= capacity) {
//             int temp = capacity / coins_array[i];
//             capacity -= temp * coins_array[i];
//             selected_coins[i] = coins_array[i];
//             selected_counts[i] = temp;
//             temp_value += (temp * coins_array[i]);
//         }
//     }

//     return temp_value;
// }

int main() {
    int length = 5;
    int coins_array[] = {2, 5, 10, 25, 50};
    int capacity = 141;

    int selected_coins[length];
    int selected_counts[length];

    // Initialize the arrays to zero
    for (int i = 0; i < length; i++) {
        selected_coins[i] = 0;
        selected_counts[i] = 0;
    }

    printf("Capacity: %d\n", capacity);
    printf("Coins: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", coins_array[i]);
    }
    printf("\n");

    my_insertion_sort_for_integer_array(coins_array, length, 1);
    int temp_value = my_making_change_greedy(length, coins_array, capacity, selected_coins, selected_counts);

    printf("Change needed for capacity %d:\n", capacity);
    for (int i = 0; i < length; i++) {
        if (selected_counts[i] > 0) {
            printf("We need %d coin(s) of %d rupees = %d\n", selected_counts[i], selected_coins[i], (selected_counts[i] * selected_coins[i]));
        }
    }

    if (temp_value < capacity) {
        printf("Can generate change for %d only with given coins, %d is remaining.\n", temp_value, (capacity - temp_value));
    }

    return 0;
}
