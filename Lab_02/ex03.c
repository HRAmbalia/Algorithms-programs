// Simple Merge sort - While loop


#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void merge(int list[], int low, int mid, int high);

// void my_merge_sort_while(int arr[], int length) {
//     for (int i=1;i<=length-1;i=2*i) {
//         for (int left_start=0;left_start<length-1;left_start+=2*i) {
//             int mid = left_start+i-1;
//             int right_end = (left_start+2*i-1<length-1) ? (left_start+2*i-1) : (length-1);
//             merge(arr, left_start, mid,right_end);
//         }
//     }
// }

// void merge(int list[], int low, int mid, int high) {
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

    printf("Merge sort using While loop(without recursion)\n");

    printf("Before sorting :\n");
    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    // 
    my_merge_sort_while(list, length);
    // 

    printf("After sorting :\n");
    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
