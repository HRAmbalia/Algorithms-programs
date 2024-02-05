// Insertion sort

#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// void print_array(int arr[], int size) {
//     for (int i=0;i<size;i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

int main() {
    int length = 10;
    struct timespec start, end;

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    int intList[] = {51, 1, 3, 56, 21, 49, 59, 30, 48, 98, 22};
    /* Best case - Minimum Swapping*/
    // int intList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    // Average time taken : 2002740.5(10 test cases)

    /* Worst case - Maximum swapping */
    // int intList[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // Average time taken : 2312648.5(10 test cases)

    /* Average case - Average swapping */
    // int intList[] = {54, 23, 12, 87, 45, 67, 91, 32, 78, 60, 41, 19, 89, 36, 75, 28, 53, 65, 95, 14, 83, 9, 70, 47, 98, 10, 68, 55, 27, 71, 94, 49, 6, 80, 42, 73, 88, 20, 64, 34, 3, 99, 31, 59, 81, 37, 22, 50, 72, 15, 93, 85, 26, 8, 62, 58, 33, 16, 44, 76, 13, 38, 21, 2, 56, 86, 46, 96, 77, 5, 18, 67, 66, 52, 11, 7, 61, 30, 1, 79, 25, 40, 43, 97, 63, 84, 92, 48, 4, 29, 24, 17, 35, 82, 51, 69, 57, 74, 39, 90, 59};
    // Average time taken : 2126839.8(10 test cases)

    clock_gettime(CLOCK_MONOTONIC, &start);

    /* ---------------------- METHOD 01 - Simple direct method ---------------------- */
    // for (int i=1;i<length;i++) {
    //     int current = intList[i];
    //     int j = i-1;

    //     while(intList[j]>current && j>=0) {
    //         intList[j+1] = intList[j];
    //         j--;
    //     }
    //     print_array(intList, length);
    //     intList[j+1] = current;
    // }
    /* ---------------------- METHOD 02 - Calls predefined function ---------------------- */
    /* This function will sort the passed integer array, while printing array for each stage */
    my_insertionSort_asc_for_integer_array(intList, length);
    /* ----------------------------------------------------------------------------------- */

    clock_gettime(CLOCK_MONOTONIC, &end);


    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
    for (int i=0;i<length;i++) { 
        printf("%d ", intList[i]);
    }
    printf("\nIt took %lld nano seconds\n", elapsed_ns);
    
    long maxrss = usage.ru_maxrss;
    printf("Approximate memory usage: %ld KB\n", maxrss);

    return 0;
}
