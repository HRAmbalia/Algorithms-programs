// Simple Merge sort - Recursion

#include <stdio.h>
#include <stdlib.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void merge(int list[], int low, int mid, int high);

// void my_merge_sort_recursion(int arr[], int p, int r) {
//     int q;
//     if (p < r) {
//         q = (p + r) / 2;
//         merge_sort_recursion(arr, p, q);
//         merge_sort_recursion(arr, q + 1, r);
//         merge_for_recursion(arr, p, q, r);
//     }
// }

// void merge_for_recursion(int list[], int low, int mid, int high) {
//     int n1 = mid-low+1;
//     int n2 = high-mid;
//     int arr1[n1], arr2[n2];
//     for (int i=0;i<n1;i++) {
//         arr1[i] = list[low+i];
//     }
//     for (int i=0;i<n2;i++) {
//         arr2[i] = list[mid+i+1];
//     }

//     int i=0,j=0,k=low;
//     while (i < n1 && j < n2) {
//         if (arr1[i] <= arr2[j]) {
//             list[k] = arr1[i];
//             i++;
//         } else {
//             list[k] = arr2[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1) {
//         list[k] = arr1[i];
//         i++;
//         k++;
//     }
//     while (j < n2) {
//         list[k] = arr2[j];
//         j++;
//         k++;
//     }
// }

int main() {
    int list[] = {12, 13, 26, 78, 89, 10, 14, 21, 28, 36, 48};
    int length = 11;

    printf("Merge sort using Recursion\n");

    printf("Before sorting :\n");
    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    // 
    my_merge_sort_recursion(list, 0, length-1);
    // 
    
    printf("After sorting :\n");
    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
