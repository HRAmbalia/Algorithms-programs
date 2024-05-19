// NAÏVE METHOD.(ITERATIVE)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// int my_naive_string_match(char array[], char pattern[]) {
//     /*
//         Input : 
//             - array: A character array (string) in which we want to find the pattern.
//             - pattern: A character array (string) that we want to search for in the array.
            
//         Output : 
//             - Returns the starting index of the first occurrence of the pattern in the array.
//             - Returns -1 if the pattern is not found in the array.
            
//         Explanation : 
//             - This function implements a naive string matching algorithm.
//             - It iterates through each position in the array and checks if the substring starting
//               from that position matches the pattern.
//             - If a match is found, it returns the starting index.
//             - If no match is found after checking all positions, it returns -1.
//     */

//     int array_len = strlen(array);
//     int pattern_len = strlen(pattern);
//     if (pattern_len>array_len) {
//         return -1;
//     }
//     for( int i=0;i<array_len;i++ ) {
//         // printf("Outer Loop: i = %d\n", i);
//         int j;
//         for( j=0;j<pattern_len;j++ ) {
//             // printf("Inner Loop: j = %d\n", j);
//             if( array[i+j]==pattern[j]) {
//                 // printf("array[%d+%d] (%c) equal to pattern[%d] (%c)\n", i, j, array[i + j], j, pattern[j]);
//                 continue;
//             }
//             else {
//                 // printf("array[%d+%d] (%c) not equal to pattern[%d] (%c)\n", i, j, array[i + j], j, pattern[j]);
//                 break;
//             }
//         }
//         if(j==pattern_len) {
//             return i;
//         }
//     }
// }

int main() {
    char array[] = "Hello how are you";
    char pattern[] = "are";
    int res = my_naive_string_match(array, pattern);
    if(res==-1) { 
        printf("Pattern not found\n");
    }
    else { 
        printf("Found at : %d\n", res);
    }
}
