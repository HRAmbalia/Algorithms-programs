// Quick sort - Using reccursion(Last element as PIVOT)

#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void swap_two_variable(int *a, int *b) {
//   int t = *a;
//   *a = *b;
//   *b = t;
// }

// int temp_partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int o = low-1;
//     for (int i=low;i<high;i++) {
//         if(arr[i]<=pivot) {
//             o = o+1;
//             swap_two_variable(&arr[o], &arr[i]);
//         }
//     }
//     swap_two_variable(&arr[o+1], &arr[high]);
//     return (o+1);
// }

// void my_quick_sort_recursion(int arr[], int low, int high) {
//     if (low<high) {
//         int pivot = temp_partition(arr, low, high);
//         my_quick_sort_recursion(arr, low, pivot-1);
//         my_quick_sort_recursion(arr, pivot+1, high);
//     }
// }

int main() {
    int list[] = {1222, 13, 26, 78, 89, 10, 14, 21, 28, 36, 48};
    int length = 11;

    printf("Quick sort using While loop(Using recursion)\n");

    printf("Before sorting :\n");
    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    // 
    my_quick_sort_asc_recursion(list, 0, length-1);
    // 

    printf("After sorting :\n");
    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
