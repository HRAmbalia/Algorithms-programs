#include <stdio.h>

void insertion_sort(int arr[], int size, int order) {
    /*
        Input: integer Array, Integer length of the array, Integer order (0 for ascending, 1 for descending)
        Output: void, prints array at each stage and level
        Explanation: This function will sort the given array based on the specified order.
    */

    if( order!=0 && order!=1 ) {
        printf("Error: Invalid order specified. Use 0 for ascending or 1 for descending.\n");
        return;
    }

    for( int i=1;i<size;i++ ) {
        int current = arr[i];
        int j = i-1;

        // Adjust the comparison based on the order parameter
        while ( (order==0 && j>=0 && arr[j]>current) || (order==1 && j>=0 && arr[j]<current)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort in descending order
    insertion_sort(arr, size, 0);

    // Print the final sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
