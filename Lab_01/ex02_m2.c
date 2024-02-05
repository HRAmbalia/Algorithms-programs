#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"


int main() {
    int length;
    printf("Enter an size for magic Square : ");
    scanf("%d", &length);
    if (length%2==0) {
        printf("Enter odd number\n");
        exit(0);
    }
    struct timespec start, end;
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    clock_gettime(CLOCK_MONOTONIC, &start);

    /* ---------------------- METHOD 01 - Simple direct method ---------------------- */
    // int r = length;
    // int c = length;
    // int i, j, range;

    // if(length%2==0) {
    //     printf("Enter odd number\n");
    //     exit (0);
    // }

    // int count = 1;
    // int mat[length][length];
    // for (int i=0;i<length;i++) {
    //     for (int j=0;j<length;j++) {
    //         mat[i][j] = 0;
    //     }
    // }

    // range = r*c;
    // i = 0;
    // j = c/2;
    // mat[i][j] = count;

    // while(count<range) {
    //     count++;

    //     if(( (i-1)<0 || (i-1)>length-1) && ( (j-1)<0 || (j-1)>length-1) ) {
    //         i = i+1;
    //     }
    //     else if((i-1)<0 || (i-1)>length-1) {
    //         i = c-1;
    //         j = j-1;
    //     }
    //     else if((j-1)<0 || (j-1)>length-1) {
    //         j = c-1;
    //         i = i-1;
    //     }
    //     else if((mat[i-1][j-1]!=0)) {
    //         i = i+1;
    //     }
    //     else {
    //         i = i-1;
    //         j = j-1;
    //     }
    //     mat[i][j] = count;
    // }

    // for (int i=0;i<length;i++) {
    //     for (int j=0;j<length;j++) {
    //         printf("%d  ", mat[i][j]);
    //     }
    //     printf("\n");
    // }

    /* ---------------------- METHOD 02 - Calls predefined function ---------------------- */
    /* This function will create magic square for given size and will return the pointer to that 2d function */
    int** matrix = my_generate_magic_square(length);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    /* ----------------------------------------------------------------------------------- */

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
    printf("\nIt took %lld nano seconds\n", elapsed_ns);

    long maxrss = usage.ru_maxrss;
    printf("Approximate memory usage: %ld KB\n", maxrss);

    // Freeing the allocated memory
    for (int i = 0; i < length; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;

}
